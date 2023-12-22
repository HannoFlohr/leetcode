class Solution {
private:
    bool canForm(string& word, unordered_map<char,int>& dict) {
        unordered_map<char,int> w;
        for(char c : word) {
            w[c]++;
            if(w[c] > dict[c]) 
                return false;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        unordered_map<char,int> dict;
        for(char c : chars)
            dict[c]++;

        for(string& word : words) {
            if(canForm(word, dict)) 
                count += word.length();
        }

        return count;
    }
};
//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/