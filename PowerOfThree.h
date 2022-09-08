class Solution {
public:
    /*
    if n is power of 3 than 
    any m<=n that is power of 3 divides n
    biggest power of 3 for signed 32bit integer < 2^31 = 3^19
    */
    bool isPowerOfThree(int n) {
        return n > 0 && (int)pow(3,19) % n == 0;
    }
};
//https://leetcode.com/problems/power-of-three/