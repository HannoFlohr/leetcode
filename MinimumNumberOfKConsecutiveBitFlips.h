class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), total_flips = 0, flips_in_window = 0;
    
        //sliding window, keep tracks of how many bits have to be flipped in current window
        for(int i = 0; i < n; ++i) {
            //remove flip for bit that leaves current window
            if(i >= k && nums[i-k] > 1) {
                --flips_in_window;
                //reverse marking
                nums[i-k] -= 2;
            }
            //flip needed for i if amount of 
            //flips in the current window is even and nums[i] is 0
            //or flips is odd and nums[i] is 1
            if(nums[i] == flips_in_window % 2) {
                if(i + k > n) {
                    return -1;
                }
                //mark for flip
                nums[i] += 2;
                ++flips_in_window;
                ++total_flips;
            }
        }

        return total_flips;
    }
};
//https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/