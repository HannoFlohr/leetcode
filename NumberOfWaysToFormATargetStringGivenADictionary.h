class Solution {
private:
    const int MOD = 1e9+7;

public:
    int numWays(vector<string>& words, string target) {
        int word_length = words[0].size();
        int target_length = target.size();

        //count the amount of each char a..z at each position in the words
        vector<vector<int>> count (word_length+1, vector<int>(26,0));
        vector<int> dp (target_length+1, 0);
        dp[0] = 1;

        for(const string& word : words)
            for(size_t i = 0; i < word_length; ++i)
                count[i][word[i]-'a']++;

        for(int i = 0; i < word_length; ++i) {
            for(int j = target_length-1; j >= 0; --j) {
                dp[j+1] += (int)((long)dp[j] * count[i][target[j]-'a'] % MOD);
                dp[j+1] %= MOD;
            }
        }

        return dp[target_length];
    }
};
//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/