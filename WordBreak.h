class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        vector<bool> dp (s.size()+1, false); //dp[i] true if a word from the dictionary can end at i
        dp[0] = true;

        //compare substring from i backward to the words in the dictionary
        for(int i=1; i<=s.size(); i++) 
            for(int j=i-1; j>=0; j--) 
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end() ) {
                    dp[i] = true;
                    break;
                }
        
        return dp[s.size()];
    }
};
//https://leetcode.com/problems/word-break/