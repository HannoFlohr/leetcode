class Solution {
private:
    struct Robot {
        int position, health, index;
        char direction;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        //create robot object for each one and sort by position
        vector<Robot> robots;
        for(int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], i, directions[i]});
        }
        sort(robots.begin(), robots.end(), [](const Robot& r1, const Robot& r2) {
            return r1.position < r2.position;
        });

        //loop through all sorted robots
        vector<Robot> st;
        for(Robot& r : robots) {
            //if current robot moves right, put it on the stack (gets checked later) and continue
            if(r.direction == 'R') {
                st.push_back(r);
                continue;
            }

            bool destroyed = false;
            //if robot moves left: process the stack and eliminate robots with no remaining health
            while(!st.empty() && st.back().health <= r.health && st.back().direction == 'R') {
                if(st.back().health == r.health) {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                r.health--;
                st.pop_back();
            }
            //if robot want destroyed yet and the robot on top of the stack moves right but has less health
            //-> robot gets destroyed and robot on top of stack reduced
            if(!destroyed && !st.empty() && st.back().direction == 'R' && st.back().health > r.health) {
                st.back().health--;
                destroyed = true;
            }
            //put on stack if robot is not destroyed
            if(!destroyed) {
                st.push_back(r);
            }
        }

        //sort remaining robots by initial index
        sort(st.begin(), st.end(), [](const Robot& r1, const Robot& r2){
            return r1.index < r2.index;
        });

        vector<int> remaining;
        for(const Robot& r : st) {
            remaining.push_back(r.health);
        }
        return remaining;
    }
};
//https://leetcode.com/problems/robot-collisions/