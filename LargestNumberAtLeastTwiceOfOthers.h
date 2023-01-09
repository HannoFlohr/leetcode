class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1, second_largest = -1, index_largest = -1;

        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] > largest) {
                second_largest = largest;
                largest = nums[i];
                index_largest = i;
            }
            else 
                second_largest = max(second_largest, nums[i]);
        }

        return (largest >= second_largest * 2) ? index_largest : -1;
    }
};
//https://leetcode.com/problems/largest-number-at-least-twice-of-others/