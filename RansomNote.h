class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r (26, 0);
        vector<int> m (26, 0);
        
        for(auto s:ransomNote)
            r[s-'a']++;
        for(auto s:magazine)
            m[s-'a']++;
        
        for(int i=0; i<26; i++)
            if(m[i] < r[i])
                return false;
        
        return true;
    }
};
//https://leetcode.com/problems/ransom-note/

/* alternative solution with unordered_maps - vectors ran faster with less space needed

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r;
        unordered_map<char, int> m;
        
        for(auto s:ransomNote)
            r[s]++;
        for(auto s:magazine)
            m[s]++;
        
        for(auto i:r)
            if(m[i.first] < i.second)
                return false;
        
        return true;
    }
};

*/