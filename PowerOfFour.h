class Solution {
public:
    /*
    n is a power of 4 if
    1) only one bit is set in binary representation (= n is power of 2)
    2) count of zero bits before the set bit is even
    */
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        
        //check condition 1)
        if(n && !(n&(n-1))) {
            //count 0 bits
            int count = 0;
            while(n>1) {
                n >>= 1;
                count++;
            }
            
            //check condition 2)
            return (count%2 == 0) ? true : false;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/power-of-four/