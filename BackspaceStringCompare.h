class Solution {
private: 
    string cleanUp(string& s) {
        vector<char> c_stack;
        for(auto &c : s) {
            if(c != '#') 
                c_stack.push_back(c); 
            else if(c_stack.size()) 
                c_stack.pop_back();
        }
        string result = "";
        for(auto &c : c_stack)
            result += c;
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return cleanUp(s) == cleanUp(t);
    }
};
//https://leetcode.com/problems/backspace-string-compare/