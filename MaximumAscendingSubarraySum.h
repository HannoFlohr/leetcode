class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0, cur_sum = nums[0];

        for(size_t i=1; i<nums.size(); i++) {
            if(nums[i-1] < nums[i]) 
                cur_sum += nums[i];
            else {
                max_sum = max(max_sum, cur_sum);
                cur_sum = nums[i];
            }
        }

        max_sum = max(max_sum, cur_sum);

        return max_sum;
    }
};
//https://leetcode.com/problems/maximum-ascending-subarray-sum/