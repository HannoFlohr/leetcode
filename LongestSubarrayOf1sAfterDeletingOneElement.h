class Solution {
private:
    void findLongestSubarray(const vector<int>& nums, int index, int count_ones, bool deleted, int& longest) {
        if(index >= nums.size() || (nums[index] == 0 && deleted)) {
            longest = max(longest, count_ones);
            return;
        }
        
        if(nums[index] == 1) 
            findLongestSubarray(nums, index+1, count_ones+1, deleted, longest);
        else { // == 0
            //delete the 0 and keep 1's
            findLongestSubarray(nums, index+1, count_ones, true, longest);
            //don't delete, reset 1's
            findLongestSubarray(nums, index+1, 0, false, longest);
        }

    }

public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        findLongestSubarray(nums, 0, 0, false, longest);
        return longest - (longest == nums.size() ? 1 : 0);
    }
};
//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/