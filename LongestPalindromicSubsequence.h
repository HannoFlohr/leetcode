class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const size_t n = s.size();
        vector<int> dp(n, 0), dp_prev(n, 0);

        for(int i=n-1; i>=0; i--) {
            dp[i] = 1;
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j])
                    dp[j] = dp_prev[j-1] + 2;
                else
                    dp[j] = max(dp_prev[j], dp[j-1]);
            }

            swap(dp, dp_prev);
        }
        
        return dp_prev[n-1];
    }
};
//https://leetcode.com/problems/longest-palindromic-subsequence/