class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int MOD = 1e9+7, n = locations.size();
        vector<vector<int>> dp (n, vector<int>(fuel+1, 0));

        for(int i = 0; i <= fuel; ++i)
            dp[finish][i] = 1;

        for(int f = 0; f <= fuel; ++f) {
            for(int city = 0; city < n; ++city) {
                for(int next = 0; next < n; ++next) {
                    if(next != city && f >= abs(locations[next] - locations[city])) {
                        dp[city][f] = (dp[city][f] + dp[next][f - abs(locations[next] - locations[city])]) % MOD;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};
//https://leetcode.com/problems/count-all-possible-routes/