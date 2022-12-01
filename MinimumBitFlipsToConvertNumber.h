class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip = 0, x = start ^ goal;
        while(x) {
            if(x & 1) 
                flip++;
            x >>= 1;
        }
        
        return flip;
    }
};
//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/