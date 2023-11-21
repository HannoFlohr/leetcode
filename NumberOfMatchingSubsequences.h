class Solution {
private:
    bool isSubsequence(const string& s, const string& t) {
        int found = 0;

        for(int i = 0; i < t.size() && found < s.size(); ++i) {
            if(s[found] == t[i]) {
                ++found;
            }
        }

        return found == s.size();
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int matching_subsequences = 0;

        unordered_map<string,int> wordcount; 
        for(const string& word : words) {
            wordcount[word]++;
        }

        for(const auto& [word,count] : wordcount) {
            if(isSubsequence(word, s)) {
                matching_subsequences += count;
            }
        }
        return matching_subsequences;
    }
};
//https://leetcode.com/problems/number-of-matching-subsequences/