class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0, min_i = -1, max_i = -1, bad_i = -1;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < minK || nums[i] > maxK) {
                bad_i = i;
            }
            if(nums[i] == minK) {
                min_i = i;
            }
            if(nums[i] == maxK) {
                max_i = i;
            }

            count += max(0LL, min(min_i, max_i) - bad_i);
        }

        return count;
    }
};
//https://leetcode.com/problems/count-subarrays-with-fixed-bounds/