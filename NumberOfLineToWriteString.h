class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int cur_line = 0, count_lines = 1;

        for(char c : s) {
            if(cur_line + widths[c-'a'] > 100) {
                count_lines++;
                cur_line = 0;
            }

            cur_line += widths[c-'a'];
        }

        return {count_lines, cur_line};
    }
};
//https://leetcode.com/problems/number-of-lines-to-write-string/