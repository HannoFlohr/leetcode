class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        vector<bool> dp (s.size()+1, false); //dp[i] true if a word from the dictionary can end at i
        dp[0] = true;

        //compare substring from end backward to the words in the dictionary
        for(int end = 1; end <= s.size(); ++end) 
            for(int start = end-1; start >= 0; --start) 
                if(dp[start] && find(wordDict.begin(), wordDict.end(), s.substr(start, end-start)) != wordDict.end() ) {
                    dp[end] = true;
                    break;
                }
        
        return dp[s.size()];
    }
};
//https://leetcode.com/problems/word-break/