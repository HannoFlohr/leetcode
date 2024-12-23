class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), max_or = 0, result = 0;
        vector<int> dp (1<<n);

        for(int num : nums)
            max_or |= num;
        for(int mask = 1; mask < 1<<n; ++mask) {
            int lowest_bit = mask & -mask;
            dp[mask] = dp[mask - lowest_bit] | nums[__builtin_ctz(lowest_bit)];
            if(dp[mask] == max_or)
                ++result;
        }

        return result;
    }
};
//https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/