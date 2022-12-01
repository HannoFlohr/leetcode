class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //sort jobs by end time {end, start, profit}
        vector<vector<int>> jobs;
        for(int i=0; i<endTime.size(); i++) 
            jobs.push_back({endTime[i], startTime[i], profit[i]}); 
        sort(jobs.begin(), jobs.end());
        
        map<int,int> dp {{0,0}}; //dp[i] = profit; after i time we can make at most 'profit' money
        int cur;
        for(auto &j : jobs) {
            cur = prev(dp.upper_bound(j[1]))->second + j[2];
            if(cur > dp.rbegin()->second)
                dp[j[0]] = cur;
        } 
        
        return dp.rbegin()->second;
    }
};
//https://leetcode.com/problems/maximum-profit-in-job-scheduling/