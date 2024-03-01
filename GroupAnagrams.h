class Solution {

//returns the lexicographically lowest permutation of 's'
string lowest_permutation(const string& s) {
    vector<int> freq (26,0);
    for(char c : s)
        freq[c-'a']++;
    
    string s_hash;
    for(int f = 0; f < 26; ++f)
        s_hash += string(freq[f], f+'a');
    
    return s_hash;
}
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        //use lowest permutation of strings as key and the input strings as the values
        for(const string& s:strs) 
            m[ lowest_permutation(s) ].push_back(s);
        
        vector<vector<string>> anagrams;
        for(const auto& i : m)
            anagrams.push_back(i.second);
        
        return anagrams;
    }
};
//https://leetcode.com/problems/group-anagrams/