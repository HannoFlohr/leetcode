class Solution {
public:
    int appendCharacters(string s, string t) {
        int contains = 0;
        //count the letters of t in order that are contained in s in the same order
        for(int i = 0; i < s.size() && contains < t.size(); ++i) {
            if(s[i] == t[contains]) {
                ++contains;
            }
        }
        return t.size() - contains;
    }
};
//https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/