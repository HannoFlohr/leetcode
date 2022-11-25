class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int low = 1, high = 1;
        for(int i=1; i<nums.size(); i++) 
            if(nums[i] > nums[i-1]) high = low + 1;
            else if(nums[i] < nums[i-1]) low = high + 1;
        
        return max(low, high);
    }
};
//https://leetcode.com/problems/wiggle-subsequence/