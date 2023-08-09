class Solution {
private:
    int maxScore(const vector<string>& words, const vector<int>& score, vector<int>& count, int index) {
        if(index >= words.size())
            return 0;

        int takeWord = 0, skipWord = maxScore(words, score, count, index+1);
        bool canBeFormed = true;
        vector<int> new_count = count;

        for(const char& ch : words[index]) {
            if(--new_count[ch-'a'] < 0) {
                canBeFormed = false;
                break;
            }
            takeWord += score[ch-'a'];
        }

        if(canBeFormed)
            takeWord += maxScore(words, score, new_count, index+1);
        else
            takeWord = 0;

        return max(takeWord, skipWord);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count (26);
        for(char& ch : letters)
            count[ch-'a']++;
        return maxScore(words, score, count, 0);
    }
};
//https://leetcode.com/problems/maximum-score-words-formed-by-letters/