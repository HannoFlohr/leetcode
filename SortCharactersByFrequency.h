class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char &c : s)
            freq[c]++;
        
        map<int,vector<char>> m;
        for(auto &f : freq)
            m[f.second].push_back(f.first);
        
        s = "";
        for(auto i = m.rbegin(); i != m.rend(); i++) 
            for(auto &j : i->second)
                s += string(i->first, j);
        
        return s;
    }
};
//https://leetcode.com/problems/sort-characters-by-frequency/