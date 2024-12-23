class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unsigned int bits_set = 0, prev_bits_set = 0, cur_min = 0, cur_max = 0, prev_max = 0;

        for(unsigned int num : nums) {
            bits_set = popcount(num);

            //if set bits of current and previous number are equal: update min and max
            if(bits_set == prev_bits_set) {
                cur_min = min(cur_min, num);
                cur_max = max(cur_max, num);
            }
            //set bits not equal and cur min is smaller than the previous max -> can't be sorted
            else if(cur_min < prev_max) {
                return false;
            }
            //new amount of set bits, update accordingly
            else {
                prev_max = cur_max;
                cur_min = cur_max = num;
                prev_bits_set = bits_set;
            }
        }

        return cur_min >= prev_max;
    }
};
//https://leetcode.com/problems/find-if-array-can-be-sorted/