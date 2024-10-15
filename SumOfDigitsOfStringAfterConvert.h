class Solution {
private: 
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        int sum = 0;

        for(char c : s) 
            sum += sumOfDigits(c-'a'+1); 
        while(--k > 0) 
            sum = sumOfDigits(sum);

        return sum;
    }
};
//https://leetcode.com/problems/sum-of-digits-of-string-after-convert/