class Solution {
private: 
    vector<vector<int>> dp; 
    
    int isSubsequence(string &s, string &t, int i, int j) {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1])
            return dp[i][j] = 1 + isSubsequence(s, t, i-1, j-1);
        else
            return dp[i][j] = isSubsequence(s, t, i, j-1);
    }
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1, -1));
        
        return isSubsequence(s, t, s.size(), t.size()) == s.size();
    }
};
//https://leetcode.com/problems/is-subsequence/