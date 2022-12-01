class Solution {
private:
    bool isvowel(char c) { return (c == 'a') || (c == 'e') ||(c == 'i') ||(c == 'o') ||(c == 'u'); }
    
public:
    bool halvesAreAlike(string s) {
        int i = 0, vowels = 0;
        for( ; i<s.size()/2; i++)
            if( isvowel(tolower(s[i])) )
                vowels++;
        for( ; i<s.size(); i++)
            if( isvowel(tolower(s[i])) )
                vowels--;
        return vowels == 0;
    }
};
//https://leetcode.com/problems/determine-if-string-halves-are-alike/