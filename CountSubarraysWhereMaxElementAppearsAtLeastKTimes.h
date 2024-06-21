class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end()), max_in_current_subarray = 0;
        long long count = 0;

        for(int start = 0, end = 0; end < nums.size(); ++end) {
            if(nums[end] == max_ele) {
                max_in_current_subarray++;
            }
            while(max_in_current_subarray >= k) {
                if(nums[start++] == max_ele) {
                    max_in_current_subarray--;
                }
            }

            count += start;
        }

        return count;
    }
};
//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/