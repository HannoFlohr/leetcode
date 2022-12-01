class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> dp (s.size()+1, 0); 
        int i = 1, j = 0, n = s.size();
        
        while(i < n) {
            if(s[i] == s[j]) 
                dp[++i] = ++j;
            else if(j == 0)
                i++;
            else
                j = dp[j];
        }
        
        return dp[n] && dp[n] % (n - dp[n]) == 0;
    }
};
//https://leetcode.com/problems/repeated-substring-pattern/

/*
first compute dp[i] as the maximum number of characters the string repeats itself up to i 
e.g. for "abcabcabcabc":  0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 
last element is dp[n] = 12
so we get a repeated substring of length n - dp[n] = 3
and finally check if the string length is divisible by the substring length 
*/