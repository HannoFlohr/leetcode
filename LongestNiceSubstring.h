class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) return "";
        
        unordered_set<char> c (s.begin(), s.end());
        for(int i=0; i<s.size(); i++) 
            if(c.find((char) toupper(s[i])) == c.end() || c.find((char) tolower(s[i])) == c.end() ) {
                string s1 = longestNiceSubstring(s.substr(0, i));
                string s2 = longestNiceSubstring(s.substr(i+1));
                return s1.size() >= s2.size() ? s1 : s2;
            }
        
        return s;
    }
};
//https://leetcode.com/problems/longest-nice-substring/