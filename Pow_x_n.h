class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) 
            return 1/x * myPow(1/x, -(n+1));
        if(n==0)
            return 1;
        if(n==2) 
            return x*x;
        else
            return myPow( myPow(x, n/2), 2) * ((n%2==0) ? 1 : x);
    }
};
//https://leetcode.com/problems/powx-n/