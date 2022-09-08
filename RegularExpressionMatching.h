class Solution {
public:
    bool isMatch(string s, string p) {
        const int ss = s.size(), ps = p.size();
        
        //dp[i][j] true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp (ss+1, vector<bool>(ps+1, false));
        dp[0][0] = true;
        
        for(int i=1; i<=ps; i++)
            dp[0][i] = i>1 && p[i-1] == '*' && dp[0][i-2]; 
        
        for(int i=1; i<=ss; i++)
            for(int j=1; j<=ps; j++) {
                if(p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                else
                    dp[i][j] = dp[i][j-2] || (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j];
            }
        
        return dp[ss][ps];
    }
};
//https://leetcode.com/problems/regular-expression-matching/

/* recursive solution

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) 
            return s.empty();
        
        if(p[1] == '*') 
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0]==p[0] || p[0] == '.') && isMatch(s.substr(1), p) );
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); 
    }
};

*/
