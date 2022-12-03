class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        vector<int> freq1(26,0), freq2(26,0);
        vector<bool> hasChar1(26, false), hasChar2(26, false);
        
        for(char &c : word1)
            freq1[c-'a']++, hasChar1[c-'a'] = true;
        for(char &c : word2)
            freq2[c-'a']++, hasChar2[c-'a'] = true;
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2 && hasChar1 == hasChar2;
    }
};
//https://leetcode.com/problems/determine-if-two-strings-are-close/

/*
two requirements for valid result:
1) each char that is contained in one word is also contained in other word
2) the overall (sorted) frequency of chars of both string needs to be the same
*/