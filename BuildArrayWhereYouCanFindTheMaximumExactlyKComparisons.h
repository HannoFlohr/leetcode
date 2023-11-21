class Solution {
public:    
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1e9+7;
        //dp[i][j][k] : possible ways to build an array of length i+1 with max value k+1 and search cost j+1
        //search cost: number of elements in the array that are greater than all elements to their left
        int dp[51][101][51], pre[51][101][51]; 

        for (int j = 0; j <= m; j++) {
            dp[1][j][1] = 1;
            pre[1][j][1] = j;
        }
        
        for (int length = 2; length <= n; length++) {
            for (int max_value = 1; max_value <= m; max_value++) {
                for (int cost = 1; cost <= k; cost++) {
                    //first case: append any element from [1, max_value] to end of array
                    dp[length][max_value][cost] = (1L * max_value * dp[length-1][max_value][cost]) % MOD;
                    
                    //second case: append element max_value to end of array
                    dp[length][max_value][cost] = (dp[length][max_value][cost] + pre[length-1][max_value-1][cost-1]) % MOD;
                    pre[length][max_value][cost] = (pre[length][max_value-1][cost] + dp[length][max_value][cost]) % MOD;
                }
            }
        }

        return pre[n][m][k];
    }
};
//https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/