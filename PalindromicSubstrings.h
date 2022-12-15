class Solution {
private: 
    void expand(const string&s, int left, int right, int& counter) {
        while(left >= 0 && right < s.size() && s[left] == s[right])
            counter++, left--, right++;
    }
public:
    int countSubstrings(string s) {
        int counter = 0;

        //choose each s[i] as the "middle" of the palindrome
        //and try if expanding to left & right gives other palindromes
        for(int i=0; i<s.size(); i++) {
            expand(s, i, i, counter);
            expand(s, i, i+1, counter);
        }

        return counter;
    }
};
//https://leetcode.com/problems/palindromic-substrings/