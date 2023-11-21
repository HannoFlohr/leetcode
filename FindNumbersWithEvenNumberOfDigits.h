class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int numbers_with_even_digits = 0;

        for(int num : nums) {
            int digits = 0;
            while(num != 0) {
                ++digits;
                if(num < 100 && num%10 == 0) {
                    ++digits;
                    break;
                }
                num /= 10;
            }

            if(digits % 2 == 0) {
                ++numbers_with_even_digits;
            }
        }

        return numbers_with_even_digits;
    }
};
//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/