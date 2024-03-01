class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total_cost = neededTime[0], max_cur_cost = neededTime[0];

        for(int i = 1; i < colors.size(); ++i) {
            if(colors[i] != colors[i-1]) {
                total_cost -= max_cur_cost; //balloon with highest cost for the last color is not removed 
                max_cur_cost = 0;
            }
            total_cost += neededTime[i]; //accumulate cost while same color
            max_cur_cost = max(max_cur_cost, neededTime[i]); //track max cost for current color
        }

        return total_cost - max_cur_cost;    
    }
};
//https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

/* first approach, using a vector as a queue; all TC passed
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        vector<pair<char,int>> q;
        
        for(int i = 0; i < colors.size(); i++) {
            if(q.empty() || !q.empty() && q.back().first != colors[i]) { 
                q.push_back({colors[i],neededTime[i]});
                continue;
            }

            char color = colors[i];
            int time = neededTime[i];
            while(!q.empty() && q.back().first == color) {
                if(q.back().second > time) {
                    cost += time;
                    break;
                }
                
                cost += q.back().second;
                q.pop_back();
            }

            if(q.empty() || q.back().first != colors[i]) {
                q.push_back({colors[i],neededTime[i]});
            }
        }


        return cost;    
    }
};
*/