class Solution {
public:
    string makeGood(string s) {
        string greatstring = "";
        
        for(int i=0; i<s.size(); i++) {
            greatstring.push_back(s[i]);
            while(greatstring.size() && (greatstring.back() == s[i+1]+32 || greatstring.back() == s[i+1]-32) ) {
                greatstring.pop_back();
                i++;
            }
        }
        
        return greatstring;
    }
};
//https://leetcode.com/problems/make-the-string-great/