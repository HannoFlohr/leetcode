class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9+7; 
        vector<vector<int>> dp (n+1, vector<int>(k+1, 0));
        dp[0][0] = 1;

        for(int N = 1; N <= n; N++) {
            for(int K = 0; K <= k; K++) {
                for(int i = 0; i <= min(K, N-1); i++) {
                    dp[N][K] = (dp[N][K] + dp[N-1][K-i]) % MOD;
                }
            }
        }

        return dp[n][k];
    }
};
//https://leetcode.com/problems/k-inverse-pairs-array/

/*
1 at first position -> no inversions
2 at first position -> 1 inversion
n at first position -> n-1 inversions 

recursion: apply same logic for n-1 and k-i+1 
*/