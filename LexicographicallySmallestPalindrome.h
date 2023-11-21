class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int front = 0, back = s.length()-1;
        while(front < back) {
            if(s[front] != s[back]) { 
                s[front] = min(s[front], s[back]);
                s[back] = min(s[front], s[back]);
            }
            ++front;
            --back;
        }
        return s;
    }
};
//https://leetcode.com/problems/lexicographically-smallest-palindrome/