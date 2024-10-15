class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int cur_direction = 0, max_distance = 0, x = 0, y = 0;
        set<pair<int,int>> blocked;
        for(int i = 0; i < obstacles.size(); ++i) {
            blocked.insert({obstacles[i][0], obstacles[i][1]});
        }

        for(int command : commands) { 
            if(command == -2) {
                --cur_direction;
            }
            else if(command == -1) {
                ++cur_direction;
            } 
            else {
                for(int move = 0; move < command; ++move) { 
                    if(blocked.find({x + directions[cur_direction][0], y + directions[cur_direction][1]}) != blocked.end()) {
                        break;
                    }
                    x += directions[cur_direction][0];
                    y += directions[cur_direction][1];
                }
                max_distance = max(max_distance, x*x + y*y);
            }

            cur_direction = (cur_direction + 4) % 4;
        }

        return max_distance;
    }
};
//https://leetcode.com/problems/walking-robot-simulation/