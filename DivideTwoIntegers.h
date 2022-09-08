class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        
        bool positive = (dividend<0 == divisor<0);
        unsigned dvdnd = abs(dividend);
        unsigned dvsr = abs(divisor);
        
        unsigned result = 0;
        short power;
        while(dvdnd >= dvsr) {
            power = 0;
            while(dvdnd > (dvsr<<(power+1))) 
                power++;
            result += (1<<power);
            dvdnd -= (dvsr<<power); 
        }
        
        if(result >= (1<<31) && positive)
            return INT_MAX;
        if(result >= (1<<31) && !positive)
            return INT_MIN;
        
        return positive ? result : -result;  
    }
};
//https://leetcode.com/problems/divide-two-integers/