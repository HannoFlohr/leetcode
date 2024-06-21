class Solution {
private: 
    int getMaxDigit(int n) {
        int max_digit = -1;
        while(n > 0) {
            max_digit = max(max_digit, n%10);
            n /= 10;
        }
        return max_digit;
    }

public:
    int maxSum(vector<int>& nums) {
        int max_digit_sum = -1;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                if(getMaxDigit(nums[i]) == getMaxDigit(nums[j])) {
                    max_digit_sum = max(max_digit_sum, nums[i]+nums[j]);
                }
            }
        }
        return max_digit_sum;
    }
};
//https://leetcode.com/problems/max-pair-sum-in-an-array/