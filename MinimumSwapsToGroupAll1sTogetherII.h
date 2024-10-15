class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int count_ones = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), start = 0, end = count_ones-1, zeros = 0;

        for(int i = start; i <= end; ++i) {
            if(nums[i] == 0) {
                ++zeros;
            }
        }

        int min_swaps = zeros;
        for(int i = 0; i < n; ++i) {
            if(nums[start] == 0) {
                --zeros;
            }
            start = (start+1) % n;
            end = (end+1) % n;
            if(nums[end] == 0) {
                ++zeros;
            }

            min_swaps = min(min_swaps, zeros);
        }

        return min_swaps;
        
    }
};
//https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/