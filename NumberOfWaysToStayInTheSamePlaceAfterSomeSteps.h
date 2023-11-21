class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9+7;
        const int size = min(steps/2+1, arrLen);
        vector<int> dp (size+2), dp_last (size+2);
        dp_last[1] = 1;

        while(steps-- > 0) {
            for(int i = 1; i <= size; i++) {
                dp[i] = ((long)dp_last[i] + dp_last[i-1] + (dp_last[i+1])) % MOD;
            }
            dp_last = dp;
        }

        return dp_last[1];
    }
};
//https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/