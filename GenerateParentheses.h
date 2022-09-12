class Solution {

void makeParenthesis(vector<string> &p, string s, int open, int close) {
    if(!open && !close) {
        p.push_back(s);
        return;
    }
    
    if(open > 0) makeParenthesis(p, s+"(", open-1, close+1);
    if(close > 0) makeParenthesis(p, s+")", open, close-1);
}
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        makeParenthesis(result, "", n, 0);
        return result;
    }
};
//https://leetcode.com/problems/generate-parentheses/