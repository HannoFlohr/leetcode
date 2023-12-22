class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), pre_sum = 0, post_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> results (n);

        for(int i = 0; i < n; i++) {
            post_sum -= nums[i];
            results[i] = (nums[i] * i - pre_sum) + (post_sum - nums[i] * (n-i-1));
            pre_sum += nums[i];
        }

        return results;
    }
};
//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/