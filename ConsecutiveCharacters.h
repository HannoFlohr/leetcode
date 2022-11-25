class Solution {
public:
    int maxPower(string s) {
        int max_power = 1, same = 1;
        for(int i=1; i<s.size(); i++) 
            if(s[i-1] == s[i]) max_power = max(max_power, ++same);
            else same = 1;
        
        return max_power;
    }
};
//https://leetcode.com/problems/consecutive-characters/