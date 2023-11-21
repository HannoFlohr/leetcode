class Solution {
public:
    /*
    n is a power of 4 if
    1) only one bit is set in binary representation (= n is power of 2)
    2) count of zero bits before the set bit is even
    */
    bool isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }

        //check condition 1)
        if(!(n && !(n&(n-1)))) {
            return false;
        }
            
        //count 0 bits
        int zero_bits = 0;
        while(n > 1) {
            n >>= 1;
            zero_bits++;
        }   
        //check condition 2)
        return zero_bits % 2 == 0;
    }
};
//https://leetcode.com/problems/power-of-four/