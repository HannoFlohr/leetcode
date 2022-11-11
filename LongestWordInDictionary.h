class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        
        string longest_word; 
        unordered_set<string> dictionary;
        
        for(string &word : words) 
            if(word.size() == 1 || dictionary.count(word.substr(0, word.size()-1))) {
                if(longest_word.size() < word.size()) 
                    longest_word = word;
                dictionary.insert(word);
            }
        
        return longest_word;
    }
};
//https://leetcode.com/problems/longest-word-in-dictionary/