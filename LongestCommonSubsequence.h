class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int length1 = text1.size(), length2 = text2.size();
        vector<vector<int>> dp (length1 + 1, vector<int>(length2 + 1));

        for(int i=0; i<=length1; i++) 
            for(int j=0; j<=length2; j++) {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        return dp[length1][length2];
    }
};
//https://leetcode.com/problems/longest-common-subsequence/