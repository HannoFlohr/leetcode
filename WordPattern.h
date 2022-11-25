class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> chars_index; 
        unordered_map<string,int> words_index;
        
        istringstream in(s);
        int i=0;
        for(string word=""; in>>word; i++) {
            if(chars_index[pattern[i]] != words_index[word])
               return false;
               
             chars_index[pattern[i]] = words_index[word] = i+1;
        }
        
        return i==pattern.size();
    }
};
//https://leetcode.com/problems/word-pattern/