class Solution {
private:
    int dfs(const vector<vector<int>>& events, int cur, int k, vector<vector<int>>& dp) {
        if(k == 0 || cur >= events.size())
            return 0;
        if(dp[cur][k] != -1)
            return dp[cur][k];

        //find index of next not overlapping event
        int next_event_if_taken = upper_bound(events.begin()+cur, events.end(), events[cur][1], 
                    [](int start, const vector<int>& v){ return v[0] > start; }) - events.begin();
    
        //max of either take event or dont
        return dp[cur][k] = max(events[cur][2] + dfs(events, next_event_if_taken, k-1, dp), dfs(events, cur+1, k, dp));
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp (events.size(), vector<int>(k+1, -1));
        return dfs(events, 0, k, dp);
    }
};
//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/