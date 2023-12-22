class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int s1=0, s2=0, c1=0, c2=0;
        
        while(s1 < word1.size() && s2 < word2.size()) {
            if(word1[s1][c1++] != word2[s2][c2++]) 
                return false;
            
            if(c1 >= word1[s1].size()) 
                s1++, c1=0;
            if(c2 >= word2[s2].size()) 
                s2++, c2=0;
        }
        
        return s1 == word1.size() && s2 == word2.size();
    }
};
//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

/*

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(const auto &s : word1) s1 += s;
        for(const auto &s : word2) s2 += s;
        
        return s1 == s2;
    }
};
*/