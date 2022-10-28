class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<int,int> abc;
        for(int i=0; i<s.size(); i++)
            abc[s[i]]++, abc[t[i]]--;
        
        for(auto &i : abc)
            if(i.second)
                return false;
        
        return true;
    }
};
//https://leetcode.com/problems/valid-anagram/