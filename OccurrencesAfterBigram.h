class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        stringstream ss (text);
        string word, last_word = "", last_word2 = "";

        while(ss >> word) {
            if(last_word == second && last_word2 == first) {
                words.push_back(word);
            }
            last_word2 = last_word;
            last_word = word;
        }

        return words;
    }
};
//https://leetcode.com/problems/occurrences-after-bigram/