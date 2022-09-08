class Solution { 
public:
    string longestPalindrome(string s) {
        const short n = s.size();
        short maxLength = 1, start = 0;
        
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        for(short i=0; i<n; i++) dp[i][i] = true;
        
        //substring of length 2
        for(short i=0; i<n-1; i++) 
            if(s[i] ==s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        
        //substring with length > 2
        for(short length = 3; length<=n; length++) {
            for(short curStart=0; curStart<n-length+1; curStart++) {
                short curEnd = curStart + length - 1;
                
                if(dp[curStart+1][curEnd-1] && s[curStart] == s[curEnd]) {
                    dp[curStart][curEnd] = true;
                    
                    if(length > maxLength) {
                        start = curStart;
                        maxLength = length;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};
//https://leetcode.com/problems/longest-palindromic-substring/