class Solution {
private:
    bool setDigits(vector<bool>& has_digit, int n) {
        int cur_digit;
        while(n > 0) {
            cur_digit = n % 10;
            n /= 10;

            if(cur_digit == 0 || has_digit[cur_digit] == true)
                return false;

            has_digit[cur_digit] = true;
        }
        return true;
    }

public:
    bool isFascinating(int n) {
        if(n > 333)
            return false;

        vector<bool> has_digit (10, false);
        if(!setDigits(has_digit, n) || !setDigits(has_digit, 2*n) || !setDigits(has_digit, 3*n))
            return false;
        return true;
    }
};
//https://leetcode.com/problems/check-if-the-number-is-fascinating/