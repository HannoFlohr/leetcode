class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9+7;
        long result = 0;
        unordered_map<int,long> dp;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
                }
            }
            result = (result + dp[arr[i]]) % MOD;
        }

        return result;
    }
};
//https://leetcode.com/problems/binary-trees-with-factors/