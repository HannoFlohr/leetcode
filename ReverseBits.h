class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ( (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16);
        n = ( (n & 0xff00ff00) >> 8  | (n & 0x00ff00ff) << 8);
        n = ( (n & 0xf0f0f0f0) >> 4  | (n & 0x0f0f0f0f) << 4);
        n = ( (n & 0xcccccccc) >> 2  | (n & 0x33333333) << 2);
        n = ( (n & 0xaaaaaaaa) >> 1  | (n & 0x55555555) << 1);
        
        return n;
    }
};
//https://leetcode.com/problems/reverse-bits/

/*
a 8 bit number abcdefgh can be reversed in a divide and conquer approach using bitmasks and shifts
first step 		reversed first and second half we get:	efghabcd
second step:	reverse two pairs of numbers we get:	ghefcdab
last step: 		reverse two neighboring numbers:		hgfedcba
using 2 more steps this can be done for a 32 bit number in the same way
*/