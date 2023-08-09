class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0, close = 0, start = 0, cur = 0;

        while(cur < s.size()) {
            if(s[cur] == '(')
                open++;
            else
                close++;

            if(open == close) {
                result += s.substr(start+1, cur-start-1); 
                open = 0, close = 0;
                start = cur+1;
            }

            cur++;
        }

        return result;
    }
};
//https://leetcode.com/problems/remove-outermost-parentheses/