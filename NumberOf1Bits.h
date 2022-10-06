class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        while(n) {
            n &= (n-1);
            bits++;
        }
        return bits;
    }
};
//https://leetcode.com/problems/number-of-1-bits/

/*
using n & n-1 we set the lowest set bit to 0 in each step
e.g. 
n = 	101100
n-1 =	101011
n&n-1 = 101000
...
just count the steps to get the result		
/*
