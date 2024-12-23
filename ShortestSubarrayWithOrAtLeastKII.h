class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits (32,0);
        int result = INT_MAX;

        for(int right = 0, left = 0; right < nums.size(); ++right) {
            //increment set bits for number entering window
            for(int i = 0; i < 32; ++i) {
                if(nums[right] & (1<<i))
                    ++bits[i];
            }

            //number created by current set bits
            long num = 0;
            for(int i = 0; i < 32; ++i) {
                if(bits[i] != 0) {
                    num += (long)pow(2,i);
                }
            }

            //reduce window as much as possible
            while(num >= k && left <= right) {
                //decrement set bits for number removed from window
                result = min(result, right-left+1);
                for(int i = 0; i < 32; ++i) {
                    if(nums[left] & (1<<i))
                        --bits[i];
                }

                //update number created by current set bits
                num = 0;
                for(int i = 0; i < 32; ++i) {
                    if(bits[i])
                        num += (long)pow(2,i);
                }

                ++left;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
//https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/