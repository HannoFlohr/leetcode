class Solution {
private:
    // pre-condition: v is alphabetic ASCII, upper or lower case
    bool isVowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    
public:
    string sortVowels(string s) {
        vector<int> vowel_positions;
        vector<char> vowels;

        for(int i = 0; i < s.length(); ++i) {
            if(!isVowel(s[i]))
                continue;

            vowel_positions.push_back(i);
            vowels.push_back(s[i]);
        }

        sort(vowels.begin(), vowels.end());

        for(int i = 0; i < vowels.size(); ++i) 
            s[vowel_positions[i]] = vowels[i];
        
        return s;
    }
};
//https://leetcode.com/problems/sort-vowels-in-a-string/