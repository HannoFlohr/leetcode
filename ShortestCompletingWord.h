class Solution {
private:
    vector<int> countLetters(const string &s) {
        vector<int> letter_count (26, 0);
        for(auto &c : s) 
            if(isalpha(c))
                letter_count[tolower(c)-'a']++;

        return letter_count;
    }

    bool isCompletingWord(const vector<int> &license, const vector<int>& word) {
        for(size_t i=0; i<26; i++) 
            if(license[i] > word[i]) 
                return false;
        return true;
    }

public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> license_count = countLetters(licensePlate);
        vector<int> word_count;
        int shortest_completing_word_length = 1001;
        string shortest_completing_word = "";

        for(auto &word : words) {
            word_count = countLetters(word);

            if(!isCompletingWord(license_count, word_count)) 
                continue;

            if(word.length() < shortest_completing_word_length) {
                shortest_completing_word_length = word.length();
                shortest_completing_word = word;
            }
        }

        return shortest_completing_word;
    }
};
//https://leetcode.com/problems/shortest-completing-word/