class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int digit, position = num.size()-1, carry = 0;

        while(k > 0 || carry != 0) {
            digit = (k%10) + carry + (position >= 0 ? num[position] : 0);
            carry = digit / 10;
            digit %= 10;
            
            if(position >= 0)
                num[position] = digit;
            else
                num.insert(num.begin(), digit);

            position--;
            k /= 10;
        }

        return num;
    }
};
https://leetcode.com/problems/add-to-array-form-of-integer/