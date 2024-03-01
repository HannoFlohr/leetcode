class Solution {
private:
    bool isPalindrome(const string& s) {
        int front = 0, back = s.size()-1;
        while(front < back) {
            if(s[front] != s[back]) {
                return false;
            }
            ++front;
            --back;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& word : words) {
            if(isPalindrome(word)) {
                return word;
            }
        }

        return "";
    }
};
//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/