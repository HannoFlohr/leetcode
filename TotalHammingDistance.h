class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0, cur_bit_set;
        
        for(int i=0; i<32; i++) {
            cur_bit_set = 0;
            for(int j=0; j<nums.size(); j++)
                if(nums[j] & (1<<i))
                    cur_bit_set++;
            
            sum += cur_bit_set * (nums.size() - cur_bit_set);
        }
        
        return sum;
    }
};
//https://leetcode.com/problems/total-hamming-distance/

/*
LSB is either 0 or 1 for both numbers in a pair, or both have different LSB 
only those with different LSB contribute to overall result
-> loop through each bit 0...31 and count how many of the current bit are set in all nums[i]  (s=set, u=unset)

as only pairs with different bits will contribute to the result, the contribution will be 
s * u = s * (n - s)
add this contribution while looping through all bits
*/