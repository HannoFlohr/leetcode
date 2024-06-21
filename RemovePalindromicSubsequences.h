class Solution {
public:
    int removePalindromeSub(string s) {
        //if complete string is palindromic -> 1 operation
        if(s == string(s.rbegin(), s.rend())) {
            return 1;
        }
        //else remove all a's than all b's -> 2 operations
        return 2;
    }
};
//https://leetcode.com/problems/remove-palindromic-subsequences/