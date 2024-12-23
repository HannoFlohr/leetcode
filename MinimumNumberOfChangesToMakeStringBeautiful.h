class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        for(int i = 0; i < s.size()-1; i += 2) {
            if(s[i] != s[i+1])
                ++changes;
        }

        return changes;
    }
};
//https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/