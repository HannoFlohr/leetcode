class Solution {
private:
    vector<string> sentences;

    void makeSentences(string s, const vector<string>& wordDict, string sentence) {
        if(s == "") {
            sentences.push_back(sentence);
            return;
        }

        for(auto &word : wordDict) 
            if(word == s.substr(0, word.size())) 
                makeSentences(s.substr(word.size(), s.size()-word.size()), wordDict, sentence+(sentence.size()>0 ? " " : "")+word);
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sentences.clear();
        makeSentences(s, wordDict, "");
        return sentences;    
    }
};
//https://leetcode.com/problems/word-break-ii/