class Solution {
private:
    const int MOD = 1e9+7;

    int dfs(const string& s, int k, int i, vector<int>& dp) {
        if(i == s.size()) 
            return 1;
        if(s[i] == '0') 
            return 0;
        if(dp[i] != -1) 
            return dp[i];

        int result = 0; 
        long x = 0;
        for(int j = i; j < s.size(); ++j) {
            x = x*10 + s[j]-'0';
            if(x > k)
                break;
            result = (result + dfs(s, k, j+1, dp)) % MOD;
        }

        return dp[i] = result;
    }

public:
    int numberOfArrays(string s, int k) {
        vector<int> dp (s.size(), -1);
        return dfs(s, k, 0, dp);
    }
};
//https://leetcode.com/problems/restore-the-array/