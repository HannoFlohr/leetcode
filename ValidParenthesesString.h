class Solution {
public:
    bool checkValidString(string s) {
        int close_min = 0, close_max = 0;

        for(char c : s) {
            if(c == '(')
                close_min++, close_max++;
            else if(c == ')')
                close_min = max(close_min-1, 0), close_max--;
            else 
                close_min = max(close_min-1, 0), close_max++;

            if(close_max < 0)
                return false;
        }

        return close_min == 0;
    }
};
//https://leetcode.com/problems/valid-parenthesis-string/