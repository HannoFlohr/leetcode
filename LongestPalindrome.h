class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char_count;
        int odds = 0;
        //count the occurences of all chars in s
        for(char c : s) 
            char_count[c]++;
        //count chars with odd occurences
        for(auto &c : char_count) 
            odds += c.second & 1;
        //we can use all chars of s, but for all odd chars we must leave one except for one odd    
        return s.size() - odds + (odds > 0);
    }
};
//https://leetcode.com/problems/longest-palindrome/