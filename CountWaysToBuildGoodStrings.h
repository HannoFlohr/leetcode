class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9+7;
        vector<int> dp (high + 1);
        dp[0] = 1;
        
        for (int i = min(zero, one); i <= high; ++i) {
            if(i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if(i >= one)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
        }

        int sum = 0;
        for (int i = low; i <= high; i++) 
            sum = (sum + dp[i]) % MOD;
        
        return sum;
    }
};
//https://leetcode.com/problems/count-ways-to-build-good-strings/