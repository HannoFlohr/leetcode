class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int longest = 1, cur = 1; 
        
        for(int i=1; i<=nums.size(); i++) {
            if(i<nums.size() && nums[i-1] < nums[i])
                cur++;
            else {
                longest = max(longest, cur);
                cur = 1;
            }
        }
        
        return longest;
    }
};
//https://leetcode.com/problems/longest-continuous-increasing-subsequence/