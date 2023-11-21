class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> letters;
        
        for(char c : s) {
            ++letters[c];
        }        
        for(char c : t) {
            if(letters[c] == 0) {
                return c;
            }
            
            --letters[c];
        }
        
        return ' ';
    }
};
//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i < s.size(); ++i) {
            t[i+1] += (t[i]-s[i]);
        } 
        return t.back();
    }
};