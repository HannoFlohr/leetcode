class Solution {
public:
    string reverseWords(string s) {
        int length = s.length(), start = 0, end = 0;

        while(start < length) {
            while(end < length && s[end]  != ' ') {
                end++;
            }
            
            reverse(s.begin()+start, s.begin()+end);
            end++;
            start = end;
        }
        
        return s;
    }
};
//https://leetcode.com/problems/reverse-words-in-a-string-iii/