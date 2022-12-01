class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = 0, z = x ^ y;
        while(z > 0) {
            bits += z & 1; 
            z >>= 1; 
        }
        return bits;
    }
};
//https://leetcode.com/problems/hamming-distance/