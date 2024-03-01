class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1) 
            return nums;

        sort(nums.begin(), nums.end());

        int n = nums.size(), max_count = 0, index = 0;
        vector<int> dp (n, 0), parent(n, 0), result;
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if((nums[j] % nums[i] == 0) && (dp[i] < dp[j]+1)) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;

                    if(dp[i] > max_count) {
                        max_count = dp[i];
                        index = i;
                    }
                }
            }
        }

        for(int i = 0; i < max_count; ++i) {
            result.push_back(nums[index]);
            index = parent[index];
        }
        
        return result;
    }
};
//https://leetcode.com/problems/largest-divisible-subset/