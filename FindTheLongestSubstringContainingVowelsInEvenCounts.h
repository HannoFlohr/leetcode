class Solution {
public:
    int findTheLongestSubstring(string s) {
        const vector<int> char_map = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        int mask = 0, longest_substring = 0;
        vector<int> masks_before (32,-1);

        for(int i = 0; i < s.size(); ++i) {
            mask ^= char_map[s[i]-'a'];
            if(mask != 0 && masks_before[mask] == -1)  
                masks_before[mask] = i;
            longest_substring = max(longest_substring, i-masks_before[mask]);
        }

        return longest_substring;
    }
};
//https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/