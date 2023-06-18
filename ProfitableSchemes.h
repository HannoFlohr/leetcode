class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9+7;
        int cur_group, cur_profit, result = 0;
        vector<vector<int>> dp (minProfit+1, vector<int>(n+1,0)); //dp(i,j) = count of schemes with profit i using j members
        dp[0][0] = 1;

        for(int i = 0; i < group.size(); ++i) {
            cur_group = group[i]; 
            cur_profit = profit[i];

            for(int p = minProfit; p >= 0; --p) 
                for(int g = n - cur_group; g >= 0; --g)
                    dp[min(p+cur_profit, minProfit)][g+cur_group] = (dp[min(p+cur_profit, minProfit)][g+cur_group] + dp[p][g]) % MOD;
        }

        for(auto& i : dp[minProfit])
            result = (result + i) % MOD;

        return result;
    }
};
//https://leetcode.com/problems/profitable-schemes/