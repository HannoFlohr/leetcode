class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordcount;
        for(string w:words)
            wordcount[w]++;
        
        vector<int> indices;
        int n = s.length(), wordsize = words.size(), wordlength = words[0].size();
        if(!n || !wordsize) 
            return indices;
        
        for(int i=0; i<n-wordsize*wordlength+1; i++) {
            unordered_map<string, int> found;
            int j=0;
            string word;
            
            while(j<wordsize) {
                word = s.substr(i+j*wordlength, wordlength);
                if(wordcount.find(word) != wordcount.end()) {
                    found[word]++;
                    if(found[word] > wordcount[word])
                        break;
                }
                else
                    break;
                
                j++;
            }
            
            if(j == wordsize)
                indices.push_back(i);
        }
        
        return indices;
    }
};
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/