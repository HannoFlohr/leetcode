class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for(const auto& word : words) 
            if(word == s.substr(0, word.length()))
                ++count;

        return count;
    }
};
//https://leetcode.com/problems/count-prefixes-of-a-given-string/