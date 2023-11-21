class Solution {
public:
    string reverseOnlyLetters(string s) {
        int front = 0, back = s.length()-1;

        while(front < back) {
            if(!isalpha(s[front])) {
                front++;
            }
            else if(!isalpha(s[back])) {
                back--;
            }
            else {
                swap(s[front], s[back]);
                front++;
                back--;
            }
        }

        return s;
    }
};
//https://leetcode.com/problems/reverse-only-letters/