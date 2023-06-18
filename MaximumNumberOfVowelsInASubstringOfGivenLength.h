class Solution {
private:
    const bool isvowel [26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
public:
    int maxVowels(string s, int k) {
        int cur_vowels = 0, max_vowels = 0;

        for(int i = 0; i < s.length(); ++i) {
            if(isvowel[s[i]-'a'])
                cur_vowels++;
            if(i >= k && isvowel[s[i-k]-'a'])
                cur_vowels--;

            max_vowels = max(max_vowels, cur_vowels);
        }

        return max_vowels;
    }
};
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/