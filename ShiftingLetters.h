class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long int shift_count = 0;

        for(int i = s.length()-1; i >= 0; --i) {
            s[i] = ((s[i]-'a') + (shift_count + shifts[i])%26 ) % 26 + 'a';
            shift_count = (shift_count + shifts[i]) % 26; 
        }

        return s;
    }
};
//https://leetcode.com/problems/shifting-letters/