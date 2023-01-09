class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.length();
        vector<int> open;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(') 
                open.push_back(i);
            else if(s[i] == ')') {
                if(open.size()) open.pop_back();
                else s[i] = '#';
            }
        }
        
        while(open.size() > 0) {
            s[open.back()] = '#';
            open.pop_back();
        }
        
        s.erase(remove(s.begin(), s.end(), '#'), s.end());

        return s;
    }
};
//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/