class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0, digit_sum = 0;
        for(int n : nums) {
            element_sum += n;
            while(n > 0) {
                digit_sum += (n%10);
                n /= 10;
            }
        }
        return element_sum-digit_sum;
    }
};
//https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/