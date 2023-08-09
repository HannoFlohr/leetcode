class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int most_words = 0;
        for(string& s : sentences) 
            most_words = max(most_words, (int)(count(s.begin(), s.end(), ' '))+1 );
        return most_words;
    }
};
//https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/