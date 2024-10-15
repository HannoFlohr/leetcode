class Solution {
public:
    string reverseParentheses(string s, int start = 0) {
        vector<int> open_indices;
        string result;

        for(char c : s) {
            if(c == '(') {
                open_indices.push_back(result.size());
            }
            else if(c == ')') {
                int start = open_indices.back();
                open_indices.pop_back();
                reverse(result.begin() + start, result.end());
            }
            else {
                result += c;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/