class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        //transform distance to arrival time, and sort arrivals
        for(int i = 0; i < dist.size(); i++) {
            dist[i] = (dist[i]-1) / speed[i];
        }
        sort(dist.begin(), dist.end());

        //starting at time 0, 1 monster can be eliminated each minute
        for(int time = 0; time < dist.size(); time++) {
            //distance of next monster is closer than when it can be eliminated -> cant eliminate anymore
            if(dist[time] < time) {
                return time;
            }
        }

        return dist.size();
    }
};
//https://leetcode.com/problems/eliminate-maximum-number-of-monsters/