class Solution {
private: 
    //count pairs of numbers in nums with sum less than value
    long long countLessThanValue(vector<int>& nums, int value) {
        long long count = 0;
        for(int left = 0, right = nums.size() - 1; left < right; ++left) {
            while(left < right && nums[left] + nums[right] > value)
                --right;
            count += right - left;
        }
        return count;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countLessThanValue(nums, upper) - countLessThanValue(nums, lower-1);
    }
};
//https://leetcode.com/problems/count-the-number-of-fair-pairs/