class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), result = 0, max_length = 0;
        vector<pair<int,int>> dp (n, {1,1});

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] <= nums[j])
                    continue;

                if(dp[i].first == dp[j].first+1)
                    dp[i].second += dp[j].second;
                else if(dp[i].first < dp[j].first+1)
                    dp[i] = {dp[j].first+1, dp[j].second}; 
            }

            if(max_length == dp[i].first)
                result += dp[i].second;
            else if(max_length < dp[i].first) {
                max_length = dp[i].first;
                result = dp[i].second;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/number-of-longest-increasing-subsequence/