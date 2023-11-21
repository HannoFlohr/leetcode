class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> frequency;
        for(char c : s) {
            frequency[c]++;
        }
        
        const int check = frequency[s[0]];
        for(auto& it : frequency) {
            if(it.second != check) {
                return false;
            }
        }

        return true;
    }
};
//https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/