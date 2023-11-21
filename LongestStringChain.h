class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
            return s1.length() < s2.length();
        });
        
        unordered_map<string,int> dp;
        int longest_chain = 0;

        for(const string& word : words) {
            for(int i = 0; i < word.length(); ++i) {
                string s = word.substr(0, i) + word.substr(i+1); 
                dp[word] = max(dp[word], dp.find(s) == dp.end() ? 1 : dp[s]+1);
            }

            longest_chain = max(longest_chain, dp[word]);
        }

        return longest_chain;
    }
};
//https://leetcode.com/problems/longest-string-chain/