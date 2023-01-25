class Solution {
public:
    int getSum(int a, int b) {
        unsigned carry;
        while(b != 0) {
            carry = a & b;
            a ^= b;
            b = carry<<1;
        }
        return a;
    }
};
//https://leetcode.com/problems/sum-of-two-integers/

/*
if a and b don't have set bits at same positions, bitwise XOR gives the sum of a and b
to incorporate the common set bits, first compute the AND of a and b to get the carry bits
than compute the XOR value and iterate until no carry bits are left
*/