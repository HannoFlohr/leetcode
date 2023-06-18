class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit, sum = 0, prod = 1;
        while(n > 0) {
            digit = n % 10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }

        return prod - sum;
    }
};
//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/