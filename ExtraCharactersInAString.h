class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> extra_chars (n+1,0);

        for(int start = n-1; start >= 0; --start) {
            extra_chars[start] = 1 + extra_chars[start+1];

            for(const auto& word : dictionary) 
                //update if word matches substring of s starting at index start
                if(start+word.length() <= n && s.compare(start, word.size(), word) == 0)
                    extra_chars[start] = min(extra_chars[start], extra_chars[start+word.size()]);
        }

        return extra_chars[0];
    }
};
https://leetcode.com/problems/extra-characters-in-a-string/