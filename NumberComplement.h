class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1L << ((int)floor(log2(num)) + 1)) - 1);
    }
};
//https://leetcode.com/problems/number-complement/

/*
1) find number of bits in num ( floor(log2(num)+1 )
2) XORing num with 2^bits -1 gives the result
*/