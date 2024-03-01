class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        int cur, best;
        vector<int> dp (n+1, 0); //dp[i] will contain max sum from arr[0]..arr[i-1]

        for(int i = 1; i <= n; ++i) {
            cur = 0, best = 0;
            for(int K = 1; K <= k && i-K >= 0; ++K) {
                cur = max(cur, arr[i-K]);
                best = max(best, dp[i-K] + cur*K);
            }
            dp[i] = best;
        }

        return dp[n];
    }
};
https://leetcode.com/problems/partition-array-for-maximum-sum/