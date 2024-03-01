class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> char_frequency;
        for(char c : s)
            char_frequency[c]++;
        
        map<int,vector<char>> frequency_chars;
        for(auto &f : char_frequency)
            frequency_chars[f.second].push_back(f.first);
        
        s = "";
        for(auto i = frequency_chars.rbegin(); i != frequency_chars.rend(); ++i) 
            for(char c : i->second)
                s += string(i->first, c);
        
        return s;
    }
};
//https://leetcode.com/problems/sort-characters-by-frequency/