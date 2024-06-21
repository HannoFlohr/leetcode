class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {      
        int longest = 1, used_bits = 0;
        
        for(int end = 0, start = 0; end < nums.size(); ++end) {
            while((used_bits & nums[end]) != 0) {
                used_bits ^= nums[start++];
            }
            used_bits |= nums[end];
            longest = max(longest, end-start+1);
        }

        return longest;
    }
};
//https://leetcode.com/problems/longest-nice-subarray/

/*
Each element in a nice array has unique bits

use sliding window to track the used bits by OR-ing the numbers in the window

if a conflict arises, shrink window and use XOR to remove the no longer used bits 
*/