class Solution {
private:
    const int MOD = 1e9+7;
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        int n = s.size();
        char front, back;
        vector<long> dp (n+1, 0); //dp[i] means of all possible ways to decode s[0..i-1]
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1; //initialize for s[0] 
        
        for(int i=2; i<=s.size(); i++) { //compute dp for all chars of s 
            front = s[i-2], back = s[i-1]; 
            
            //combinations for current char of s
            if(back == '*')
                dp[i] += 9 * dp[i-1];
            else if(back > '0')
                dp[i] += dp[i-1]; 
            
            dp[i] %= MOD;
            
            //add combinations with regard to the char before the current one
            if(front == '*') {
                if(back == '*')     dp[i] += 15 * dp[i-2];
                else if(back < '7') dp[i] += 2 * dp[i-2];
                else                dp[i] += dp[i-2];
            }
            else if(front == '1' || front == '2') {
                if(back == '*') {
                    if(front == '1') dp[i] += 9 * dp[i-2];
                    else             dp[i] += 6 * dp[i-2];
                }
                else if((front-'0')*10 + (back-'0') <= 26)
                    dp[i] += dp[i-2];
            }
            
            dp[i] %= MOD;
        }
        
        return (int)dp[n];
    }
};
//https://leetcode.com/problems/decode-ways-ii/