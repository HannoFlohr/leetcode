class Solution {
private:
    const long MOD = 1e9+7;

    long factorialModulo (int n) {
        if(n <= 1)
            return 1;
        return (factorialModulo(n-1) * n) % MOD; 
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp (n+1, vector<long>(goal+1, 0));
    
        for(int i = k+1; i <= n; ++i) {
            for(int j = i; j <= goal; ++j) {
                if((i == j) || (i == k+1))
                    dp[i][j] = factorialModulo(i);
                else
                    dp[i][j] = (dp[i-1][j-1] * i + dp[i][j-1] * (i-k)) % MOD;
            }
        }

        return (int)dp[n][goal];
    }
};
//https://leetcode.com/problems/number-of-music-playlists/