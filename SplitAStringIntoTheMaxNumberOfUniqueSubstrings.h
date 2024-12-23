class Solution {
private:
    void maxUniqueSplit(string& s, int start_index, int& max_unique, unordered_set<string> strings) {
        if(start_index == s.size()) {
            max_unique = max(max_unique, (int)strings.size());
            return;
        }

        string sub = "";
        for(int i = start_index; i < s.size(); ++i) {
            sub += s[i];
            if(strings.contains(sub))
                continue;

            strings.insert(sub);
            maxUniqueSplit(s, i+1, max_unique, strings);
            strings.erase(sub);
        }
    }

public:
    int maxUniqueSplit(string& s) {
        int max_unique = 0;
        unordered_set<string> strings;
        maxUniqueSplit(s, 0, max_unique, strings);
        return max_unique;
    }
};
//https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/