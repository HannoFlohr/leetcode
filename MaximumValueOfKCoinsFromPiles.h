class Solution {
private:
    int solve(const vector<vector<int>>& piles, vector<vector<int>>& dp, int i, int k) {
        if(dp[i][k] > 0)
            return dp[i][k];
        if(k==0 || i==piles.size())
            return 0;

        int result = solve(piles, dp, i+1, k);
        int cur = 0;

        for(int j=0; j<piles[i].size() && j<k; ++j) {
            cur += piles[i][j];
            result = max(result, solve(piles, dp, i+1, k-j-1) + cur);
        }

        dp[i][k] = result;

        return result;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp (piles.size()+1, vector<int>(k+1, 0));
        return solve(piles, dp, 0, k);
    }
};
//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/