class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, length = pref.length();

        for(const auto& word : words)
            if(word.substr(0, length) == pref)
                ++count;

        return count;
    }
};
//https://leetcode.com/problems/counting-words-with-a-given-prefix/