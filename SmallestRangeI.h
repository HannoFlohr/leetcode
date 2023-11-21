class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        return max(0, *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) - 2*k);
    }
};
https://leetcode.com/problems/smallest-range-i/
