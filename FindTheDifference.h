class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> dict;
        for(auto &c : s)
            dict[c]++;
        
        for(auto &c : t) {
            if(dict[c] == 0) return c;
            else dict[c]--;
        }
        
        return ' ';
    }
};
//https://leetcode.com/problems/find-the-difference/