class Solution {
private: 
    int dfs(int index1, int prev, vector<vector<int>>& dp, const vector<int>& arr1, const vector<int>& arr2) {
        if(index1 == arr1.size())
            return 0;

        int index2 = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if(dp[index1][index2] != -1) 
            return dp[index1][index2];
        if(index2 == arr2.size() && arr1[index1] <= prev)
            return dp[index1][index2] = 1e9;

        int take = 1e9, dont_take = 1e9;
        if(index2 != arr2.size())
            take = dfs(index1+1, arr2[index2], dp, arr1, arr2) + 1;
        if(arr1[index1] > prev)
            dont_take = dfs(index1+1, arr1[index1], dp, arr1, arr2);

        return dp[index1][index2] = min(take, dont_take);
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp (arr1.size(), vector<int>(arr2.size()+1, -1));
        int result = dfs(0, -1, dp, arr1, arr2);
        return result == 1e9 ? -1 : result;
    }
};
//https://leetcode.com/problems/make-array-strictly-increasing/