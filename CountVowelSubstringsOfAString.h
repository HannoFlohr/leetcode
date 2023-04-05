class Solution {
private:
    bool isvowel(char ch) { 
        return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); 
    }

    //returns the number of substrings having at most 'vowels_needed' unique vowels
    int countVowelSubstrings(const string& word, int vowels_needed) {
        unordered_map<char,int> vowels;
        int start = 0, end = 0, vowel_substrings = 0;

        for( ; end < word.size(); end++) {
            if(!isvowel(word[end])) {
                start = end+1;
                vowels.clear();
                continue;
            }

            vowels[word[end]]++;

            for( ; vowels.size() > vowels_needed; start++)
                if(--vowels[word[start]] == 0)
                    vowels.erase(word[start]);
        
            vowel_substrings += end - start + 1;
        }

        return vowel_substrings;
    }

public:
    int countVowelSubstrings(string word) {
        return countVowelSubstrings(word,5) - countVowelSubstrings(word,4);
    }
};
https://leetcode.com/problems/count-vowel-substrings-of-a-string/