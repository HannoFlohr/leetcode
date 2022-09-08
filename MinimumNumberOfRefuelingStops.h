class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int station = 0, result = 0;
        while(startFuel < target) {
            while(station < stations.size() && stations[station][0] <= startFuel)
                q.push(stations[station++][1]);
            
            if(q.empty())
                return -1;
            
            startFuel += q.top();
            q.pop();
            result++;
        }
        return result;   
    }
};
//https://leetcode.com/problems/minimum-number-of-refueling-stops/