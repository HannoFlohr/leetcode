class Solution {
public:
    bool isMatch(string s, string p) {
        const int ss = s.size(), ps = p.size();
        
        //dp[i][j] true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp (ss+1, vector<bool>(ps+1, false));
        dp[0][0] = true;
        
        for(int i=0; i<ps && p[i]=='*'; i++)
            dp[0][i+1] = true; 
        
        for(int i=1; i<=ss; i++)
            for(int j=1; j<=ps; j++) {
                if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1];
            }
        
        return dp[ss][ps];
    }
};
//https://leetcode.com/problems/wildcard-matching/	