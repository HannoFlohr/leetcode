class Solution {
public:
    int longestValidParentheses(string s) {
        int t, longest = 0;
        stack<int> p;
        p.push(-1);
        
        for(int i=0; i<s.size(); i++) {
            t = p.top();
            
            if(t != -1 && s[i]==')' && s[t]=='(') {
                p.pop();
                longest = max(longest, i-p.top());
            }
            else
                p.push(i);
        }
        
        return longest;
    }
};
//https://leetcode.com/problems/longest-valid-parentheses/