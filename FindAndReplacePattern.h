class Solution {
private:
    bool wordEqualPattern(const string& word, const string& pattern) {
        unordered_map<char,char> wordToPattern;
        unordered_map<char,char> patternToWord;

        for(int i = 0; i < word.size(); ++i) {
            if(patternToWord.contains(pattern[i]) || wordToPattern.contains(word[i])) {
                if(patternToWord[pattern[i]] != word[i] || wordToPattern[word[i]] != pattern[i]) {
                    return false;
                }
                else{
                    continue;
                }
            }
            patternToWord[pattern[i]] = word[i];
            wordToPattern[word[i]] = pattern[i];
        }
        
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(const string& word : words) {
            if(wordEqualPattern(word, pattern)) {
                result.push_back(word);
            }
        }
        return result;
    }
};
//https://leetcode.com/problems/find-and-replace-pattern/