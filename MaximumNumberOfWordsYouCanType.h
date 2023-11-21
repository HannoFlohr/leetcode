class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken (26, false);
        for(char c : brokenLetters) {
            broken[c-'a'] = true;
        }

        int can_type = 0;
        string word;
        std::istringstream iss (text);
        while(iss >> word) {
            can_type++;
            for(char c : word) {
                if(broken[c-'a'] == true) {
                    can_type--;
                    break;
                }
            }
        }

        return can_type;
    }
};
//https://leetcode.com/problems/maximum-number-of-words-you-can-type/