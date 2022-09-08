class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charPos (256,-1);
        int start = -1;
        int longestSubstring = 0;
    
        for(int i=0; i<s.length(); i++) {
            if(charPos[s[i]] > start)
                start = charPos[s[i]];
            
            charPos[s[i]] = i;
            longestSubstring = max(longestSubstring, i-start);
        }
        
        return longestSubstring;
    }
};
//https://leetcode.com/problems/longest-substring-without-repeating-characters/