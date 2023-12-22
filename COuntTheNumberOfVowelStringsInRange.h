class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++) {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]))
                ++count;
        }
        return count;
    }
};
//https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/