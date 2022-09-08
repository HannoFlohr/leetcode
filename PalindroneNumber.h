class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x!=0 && x%10==0)) return false;
        
        int reverse = 0;
        while(x>reverse) {
            reverse = 10 * reverse + x%10;
            x /= 10;
        }
        
        return (x==reverse || x == reverse/10);
    }
};
//https://leetcode.com/problems/palindrome-number/

/* class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        unsigned int reverse = 0, a = x;
        while(a) {
            reverse = 10 * reverse + a%10;
            a /= 10;
        }
        
        return (x==reverse);
    }
}; */