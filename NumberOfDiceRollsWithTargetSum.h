class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp_last(target+1, 0);
        dp_last[0] = 1;

        for(int i = 1; i <= n; i++) {
            vector<int> dp (target+1, 0);
            for(int j = 1; j <= k; j++) {
                for(int t = j; t <= target; t++) {
                    dp[t] = (dp[t] + dp_last[t-j]) % 1000000007;
                }
            }

            swap(dp, dp_last);
        }

        return dp_last[target];
    }
};
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/