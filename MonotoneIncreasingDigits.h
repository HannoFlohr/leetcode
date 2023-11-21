class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int replace_index = s.length();

        for(int i = replace_index-1; i > 0; i--) {
            if(s[i] < s[i-1]) {
                replace_index = i;
                s[i-1] = s[i-1]-1;
            }
        } 

        for(int i = replace_index; i < s.length(); i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};
//https://leetcode.com/problems/monotone-increasing-digits/