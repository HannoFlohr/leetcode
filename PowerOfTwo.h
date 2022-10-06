class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && ((n & (n-1)) == 0);
    }
};
//https://leetcode.com/problems/power-of-two/

/*
each power of two has binary form 100...
so if n=10000 and n-1=01111 -> n & (n-1) = 00000
*/