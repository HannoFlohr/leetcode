class Solution {
public:
    bool isThree(int n) {
        int divisors = 2; //n is divisible by 1 and itself
        for(int i=2; i<=n/2 && divisors<=3; i++)
            if(n%i == 0)
                divisors++;
        return divisors==3;
    }
};
//https://leetcode.com/problems/three-divisors/