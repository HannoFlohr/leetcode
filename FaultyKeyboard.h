class Solution {
public:
    string finalString(string s) {
        string faulty = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'i') {
                if(i+1 < s.length() && s[i+1] == 'i') {
                    i++;
                    continue;
                }
                reverse(faulty.begin(), faulty.end());
            }
            else {
                faulty += s[i];
            }
        }
        return faulty;
    }
};
//https://leetcode.com/problems/faulty-keyboard/