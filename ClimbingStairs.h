class Solution {
public:
    int climbStairs(int n) {
        int a=1, b=1; //a: ways to get to current step, b: ways to get to next step
        while(--n)
            a = (b += a) -a;
        return b;
    }
};
//https://leetcode.com/problems/climbing-stairs/