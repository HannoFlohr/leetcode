class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        //either "change" the two highest, lowest or the lowest and the highest number (to a number already existing)
        //than the smallest difference is always 0, and the result is the min of the three options
        return min( { nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1] } );
    }
};
//https://leetcode.com/problems/minimum-score-by-changing-two-elements/