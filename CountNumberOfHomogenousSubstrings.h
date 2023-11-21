class Solution {
public:
    int countHomogenous(string s) {
        int count = 0, consecutive_char = 0, MOD = 1e9+7;
        char cur_char = s[0];
        
        for(char c : s) {
            if(c == cur_char) {
                consecutive_char++;
            }
            else {
                consecutive_char = 1;
                cur_char = c;
            }

            count = (count + consecutive_char) % MOD;
        } 

        return count;
    }
};
//https://leetcode.com/problems/count-number-of-homogenous-substrings/