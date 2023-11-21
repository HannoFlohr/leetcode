class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first (26, INT_MAX), last(26,0);
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(first[s[i]-'a'] == INT_MAX)
                first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }

        for(int i = 0; i < 26; i++) {
            if(first[i] < last[i]) {
                count += unordered_set<char>(s.begin()+first[i]+1, s.begin()+last[i]).size();
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/