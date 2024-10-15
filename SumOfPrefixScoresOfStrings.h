class Trie {
public:
    Trie* next [26] = {};
    int count = 0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie root;
        vector<int> result;

        //build trie using all words and keep count how 
        //often each node is visited
        for(string& word : words) {
            Trie* node = &root;
            for(char c : word) {
                if(!node->next[c-'a'])
                    node->next[c-'a'] = new Trie();
                node = node->next[c-'a'];
                node->count++;
            }
        }

        //sum up the counts of each prefix for each word
        //using the count values generated in the first step
        for(string& word : words) {
            Trie* node = &root;
            int count = 0;
            for(char c : word) {
                count += node->next[c-'a']->count;
                node = node->next[c-'a'];
            }
            result.push_back(count);
        }

        return result;    
    }
};
https://leetcode.com/problems/sum-of-prefix-scores-of-strings/