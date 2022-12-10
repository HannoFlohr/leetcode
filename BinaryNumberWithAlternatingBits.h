class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last_digit = n%2;
        
        while(n%2 == last_digit) {
            last_digit = 1 - last_digit;
            n /= 2;
        }
        
        return n == 0;
    }
};
//https://leetcode.com/problems/binary-number-with-alternating-bits/