class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }

        int product = 1;
        while(n > 4) {
            product *= 3;
            n -= 3;
        }

        return product*n;
    }
};
//https://leetcode.com/problems/integer-break/

/*
looking at the the results fo 2...10 one can see that solution breaks down to
2's and 3's to find the maximum product 
with at most two 2's 
*/