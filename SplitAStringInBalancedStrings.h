class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, balancedSubstrings = 0;

        for(const auto& c : s) {
            c == 'L' ? l++ : r++;

            if(l == r) {
                balancedSubstrings++;
                l = 0, r = 0;
            }
        }

        return balancedSubstrings;
    }
};
//https://leetcode.com/problems/split-a-string-in-balanced-strings/