class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0] * nums[1] * nums[2];
        
        sort(nums.begin(), nums.end());
        
        int max_sum_positive_numbers = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
        
        if(nums[0] < 0 && nums[1] < 0) {
            int other_sum = nums[0] * nums[1] * nums[nums.size()-1];
            return other_sum > max_sum_positive_numbers ? other_sum : max_sum_positive_numbers;
        }
        
        return max_sum_positive_numbers;
    }
};
//https://leetcode.com/problems/maximum-product-of-three-numbers/