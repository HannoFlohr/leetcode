class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0, ai, bi, ci;
        while(a>0 || b>0 || c>0) {
            ai = a%2; bi = b%2; ci = c%2;
            
            if(ci==1 && ai+bi==0)
                flips++;
            else if(ci==0)
                flips += ai + bi;
            
            a /= 2; b /= 2; c /= 2;
        }
        
        return flips;
    }
};
//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

/* using builtin c++17 methods

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount(c ^= a|b) + __builtin_popcount(a & b & c);
    }
};

*/