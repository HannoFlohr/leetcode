class Solution {
private:
    vector<int> countChars(const string& s) {
        vector<int> frequency (26,0);
        for(char c : s) {
            frequency[c-'a']++;
        }
        return frequency;
    }

    vector<int> commonChars(const vector<int>& a, const vector<int>& b) {
        vector<int> common (26,0);
        for(int i = 0; i < 26; ++i) {
            common[i] = min(a[i], b[i]);
        }
        return common;
    }

public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> countOfCommonChars = countChars(words[0]);
        for(int i = 1; i < words.size(); ++i) {
            countOfCommonChars = commonChars(countOfCommonChars, countChars(words[i]));
        }

        vector<string> chars;
        for(int i = 0; i < 26; ++i) {
            while(countOfCommonChars[i] > 0) {
                chars.push_back(string(1, 'a'+i));
                --countOfCommonChars[i];
            }
        }

        return chars;
    }
};
//https://leetcode.com/problems/find-common-characters/