class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> frequencies;

        for(char c : word1) {
            frequencies[c]++;
        }
        for(char c : word2) {
            frequencies[c]--;
        }

        for(auto [_,f] : frequencies) {
            if(f < -3 || f > 3) {
                return false;
            }
        }

        return true;
    }
};
//https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/