class Solution {
    bool canCross(const vector<int>& stones, int i, int k, vector<vector<int>>& dp) {
        if(i == stones.size()-1)
            return true;
        if(i >= stones.size())
            return false;
        if(dp[i][k] != -1)
            return dp[i][k];

        bool can_jump = false;
        for(int d = -1; d <= 1; ++d) {
            int next_k = k + d;
            if(next_k <= 0)
                continue;

            auto lb = lower_bound(stones.begin(), stones.end(), stones[i]+next_k) - stones.begin();
            if(lb == stones.size() || stones[lb] != stones[i]+next_k) 
                continue;

            can_jump = can_jump || canCross(stones, lb, next_k, dp);
        }

        return dp[i][k] = can_jump;
    }

public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp (stones.size()+1, vector<int>(stones.size()+1, -1));
        return canCross(stones, 0, 0, dp);
    }
};
//https://leetcode.com/problems/frog-jump/