class Solution {
private:
//returns the lexicographically lowest permutation of 's'
string lowest_permutation(string s) {
    int freq[26] = {0};
    for(auto &c:s)
        freq[c-'a']++;
    
    string s_hash;
    for(int f=0; f<26; f++)
        s_hash += string(freq[f], f + 'a');
    
    return s_hash;
}
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        //use lowest permutation of strings as key and the input strings as the values
        for(auto &s:strs) 
            m[ lowest_permutation(s) ].push_back(s);
        
        vector<vector<string>> anagrams;
        for(auto &i:m)
            anagrams.push_back(i.second);
        
        return anagrams;
    }
};
//https://leetcode.com/problems/group-anagrams/