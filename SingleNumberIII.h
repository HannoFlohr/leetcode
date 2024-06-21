class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //compute the XOR value of the nums vector and find the least significant bit
        long lsb = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        lsb &= -lsb;
        
        vector<int> singles (2,0);
        for(int n : nums) {
            if((n & lsb) == 0) //bit not set
                singles[0] ^= n;
            else //bit set
                singles[1] ^= n;
        }

        return singles;
    }
};
//https://leetcode.com/problems/single-number-iii/

/*
first compute the xor of all numbers which gets us the XOR of the two single numbers 
(as there are two distinct single numbers, at least one bit must be set) 
and the least significant bit of that XOR value

than we check for each number if the least significant bit is set or not and
xor the numbers accordingly to compute the two single values  
*/