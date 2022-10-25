class Solution {
public:
	//divide n by 2 3 5 as often as possible and check if n=1 after that
    bool isUgly(int n) {
        for(int div=2; div<6 && n; div++)
            while(n % div == 0)
                n /= div;
        
        return n == 1;
    }
};
//https://leetcode.com/problems/ugly-number/