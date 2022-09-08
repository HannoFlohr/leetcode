class Solution {
public:
    int reverse(int x) {
        int result = 0; short digit;
        while(x) {
            digit = x % 10;
            
            //overflow check
            if( (result > 0 && result > (INT_MAX - digit)/10) || (result < 0 && result < (INT_MIN - digit)/10) )
                return 0;
            
            result = result * 10 + digit;
            x /= 10;
        }
        return result;
    }
};
//https://leetcode.com/problems/reverse-integer/submissions/