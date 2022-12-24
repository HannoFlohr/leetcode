class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> chars1 (26, 0), chars2 (26, 0);
        int start = 0;

        for(auto &c : s1)
            chars1[c-'a']++;

        for(int cur = 0; cur < s2.size(); cur++) { 
            chars2[s2[cur]-'a']++;

            if(cur - start == s1.size()) {
                chars2[s2[start]-'a']--;
                start++; 
            }

            if(chars1 == chars2) 
                return true;
        }

        return false;
    }
};
//https://leetcode.com/problems/permutation-in-string/