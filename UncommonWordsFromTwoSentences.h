class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> words;
        istringstream ss (s1 + " " + s2);
        string word;
        while(ss >> word) 
            words[word]++;
        
        vector<string> uncommon;
        for(auto [word,count] : words) {
            if(count == 1)
                uncommon.push_back(word);
        }
        return uncommon;
    }
};
//https://leetcode.com/problems/uncommon-words-from-two-sentences/