class Solution {
public:
    int bitwiseComplement(int n) {
        return n>0 ? n ^ ((1u << ((int)floor(log2(n)) + 1)) - 1) : 1;
    }
};
//https://leetcode.com/problems/complement-of-base-10-integer/