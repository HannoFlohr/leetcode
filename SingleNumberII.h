class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0, k = 3, mask, count;
        
        for(int i=0; i<32; i++) {
            mask = 1 << i;
            count = 0;

            for(auto &n : nums)
                count += bool(n & mask);

            if(count % k)
                single |= mask;
        }
        
        return single;
    }
};
//https://leetcode.com/problems/single-number-ii/

/*
traverse all 32 bits and count the number of of elements this bit is set 
if the count is not a multiple of k than the cur bit is set in the single number as well
so set that bit in the result using 'OR' and the current bitmask  
*/