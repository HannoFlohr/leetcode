class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        vector<int> first_at (26, -1);
        
        for(int i=0; i<s.size(); i++) {
            freq[s[i]]++;
            if(first_at[(int)s[i]-97] = -1) 
                first_at[(int)s[i]-97] = i;              
        }
        
        int first_unique = s.size();
        for(auto &f : freq) {
            if(f.second == 1)
                first_unique = min(first_unique, first_at[(int)f.first-97]);
        }
        
        return first_unique == s.size() ? -1 : first_unique;
    }
};
//https://leetcode.com/problems/first-unique-character-in-a-string/