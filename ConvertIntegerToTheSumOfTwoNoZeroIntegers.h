class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int first = 0, second = 0, factor = 1, digit;

        while(n > 0) {
            digit = n % 10;
            n /= 10;

            if((digit == 0 || digit == 1) && n > 0) {
                first += (digit+1) * factor;
                second += factor * 9;
                n--;
            }
            else {
                first += factor;
                second += (digit-1) * factor;
            }
            
            factor *= 10;
        }
            
        return {first,second};
    }
};
//https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/