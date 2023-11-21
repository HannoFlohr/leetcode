class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> canhave (26, false);
        for(char c : allowed) {
            canhave[c-'a'] = true;
        }

        int consistent_strings = words.size();
        for(const string& word : words) {
            for(char c : word) {
                if(canhave[c-'a'] == false) {
                    --consistent_strings;
                    break;
                }
            }
        }

        return consistent_strings;
    }
};
//https://leetcode.com/problems/count-the-number-of-consistent-strings/