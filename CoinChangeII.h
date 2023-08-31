class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1);
        dp[0] = {1};

        for(int coin : coins) 
            for(int i = coin; i <= amount; ++i) 
                dp[i] += dp[i - coin];

        return dp[amount];
    }
};
//https://leetcode.com/problems/coin-change-ii/