class Solution {
    bool isValid(string& s, int left, int right, int deleted) {
        if(deleted > 1) return false;

        while(left < right) {
            if(s[left] == s[right]) 
                left++, right--;
            else
                return isValid(s, left+1, right, deleted+1) || isValid(s, left, right-1, deleted+1);
        }

        return true;
    }
public:
    bool validPalindrome(string s) {
        return isValid(s, 0, s.size()-1, 0);
    }
};
//https://leetcode.com/problems/valid-palindrome-ii/