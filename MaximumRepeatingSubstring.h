class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int max_repeating = 0;
        string repeating = word;
        while(sequence.find(repeating) != string::npos) {
            repeating += word;
            max_repeating++;
        }

        return max_repeating;
    }
};
//https://leetcode.com/problems/maximum-repeating-substring/

/*
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int wordlength = word.length(), j, repeating, max_repeating = 0;

        for(int i=0; i+wordlength <= sequence.length(); i++) {
            if(sequence.substr(i, wordlength) != word) 
                continue;

            repeating = 1;
            j = i + wordlength;

            while(j+wordlength <= sequence.length() && sequence.substr(j, wordlength) == word) {
                repeating++;
                j += wordlength;
            }

            max_repeating = max(max_repeating, repeating);
        }

        return max_repeating;
    }
};
*/