class Solution {
private:
    const int MOD = 1e9+7;

    int solve(const vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int last_value) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || last_value >= grid[i][j])
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int up = solve(grid, dp, i-1, j, grid[i][j]);
        int down = solve(grid, dp, i+1, j, grid[i][j]);
        int left = solve(grid, dp, i, j-1, grid[i][j]);
        int right = solve(grid, dp, i, j+1, grid[i][j]);
    
        dp[i][j] = (1 + up + down + left + right) % MOD;
        return dp[i][j];
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();    
        if(m == 1 && n == 1)
            return 1;

        vector<vector<int>> dp (m, vector<int>(n,-1));
        int result = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dp[i][j] == -1)
                    result += solve(grid, dp, i, j, -1);
                else
                    result += dp[i][j]; 

                result %= MOD;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/