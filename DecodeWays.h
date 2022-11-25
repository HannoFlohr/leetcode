class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1); //dp[i] means number of ways to to decode string from [i:n]
        dp[n] = 1; 
        
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '0') //leading zero not possible
                dp[i] = 0;
            else {
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')) )
                    dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};
//https://leetcode.com/problems/decode-ways/

/*
starting from end
the last number can only be represented by its corresponding letter, so dp[n-1] = 1
the other numbers i<n-1, if not zero (than dp[i]=0), can be represented by their corresponding letter times the number of ways to decode the substring after them
special case if i and i+1 are in range [10,26] -> add additional possible combinations
*/