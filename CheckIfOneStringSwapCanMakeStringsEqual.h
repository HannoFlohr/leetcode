class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char swap1 = '?', swap2;
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] == s2[i]) {
                continue;
            }

            if(swap1 == '!') {
                return false;
            }
            if(swap1 != '?') {
                if(swap1 != s2[i] || swap2 != s1[i]) {
                    return false;
                }
                swap1 = '!';
            }
            else {
                swap1 = s1[i];
                swap2 = s2[i];
            }
        }

        if(swap1 != '?' && swap1 != '!')
            return false;
        return true;
    }
};
//https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/