class Solution {
public:
    int countDigits(int num) {
        int count = 0, x = num, digit;

        while(x > 0) {
            digit = x % 10;
            x = x / 10;
            if(num % digit == 0) 
                ++count;
        }

        return count;
    }
};
//https://leetcode.com/problems/count-the-digits-that-divide-a-number/