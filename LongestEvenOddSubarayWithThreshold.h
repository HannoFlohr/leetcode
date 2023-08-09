class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int longest = 0, cur = 0, start = INT_MAX;
        
        while(cur < nums.size()) {
            if(nums[cur] > threshold || (cur > 0 && (nums[cur]%2) == (nums[cur-1]%2)) ) {
                longest = max(longest, cur - start);
                start = INT_MAX;
            }

            if(start == INT_MAX && nums[cur] <= threshold && nums[cur]%2 == 0)
                start = cur; 
            
            cur++;
        }

        return max(longest, cur - start);
    }
};
//https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/