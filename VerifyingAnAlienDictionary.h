class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alphabet (26);
        for(size_t i=0; i<order.size(); i++) 
            alphabet[order[i]-'a'] = i;

        for(string& word : words) 
            for(char& c : word)
                c = alphabet[c-'a'];

        return is_sorted(words.begin(), words.end());
    }
};
https://leetcode.com/problems/verifying-an-alien-dictionary/