class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.size()-1; ++i) 
            if(s[i] > s[i+1])
                return false;
        return true;
    }
};
//https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/