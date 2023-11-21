class Solution {
private: 
    int cleanUp(string& s) {
        int end = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                end = max(0, --end);
            }
            else {
                s[end] = s[i];
                end++;
            }
        }
        return end;
    }
public:
    bool backspaceCompare(string s, string t) {
        int s_end = cleanUp(s), t_end = cleanUp(t);

        if(s_end != t_end ) {
            return false;
        }

        for(int i = 0; i < s_end; i++) {
            if(s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.com/problems/backspace-string-compare/

/*
class Solution {
private: 
    string cleanUp(string s) {
        vector<char> c_stack;
        for(char c : s) {
            if(c != '#') 
                c_stack.push_back(c); 
            else if(c_stack.size()) 
                c_stack.pop_back();
        }
        return string(c_stack.begin(), c_stack.end());
    }
public:
    bool backspaceCompare(string s, string t) {
        return cleanUp(s) == cleanUp(t);
    }
};
*/