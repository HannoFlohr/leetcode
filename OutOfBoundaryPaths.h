class Solution {
private:
    const int MOD = 1e9+7;

    int findPaths(int m, int n, int maxMove, int row, int col, int moves, vector<vector<vector<int>>>& dp) {
        //out of bounds?
        if(row < 0 || col < 0 || row >= m || col >= n) {
            return 1;
        }
        //moves left?
        if(moves == maxMove) {
            return 0;
        }
        //already visited?
        if(dp[moves][row][col] != -1) {
            return dp[moves][row][col];
        }

        int paths = 0;
        paths = (paths + findPaths(m, n, maxMove, row-1, col, moves+1, dp)) % MOD;
        paths = (paths + findPaths(m, n, maxMove, row+1, col, moves+1, dp)) % MOD;
        paths = (paths + findPaths(m, n, maxMove, row, col-1, moves+1, dp)) % MOD;
        paths = (paths + findPaths(m, n, maxMove, row, col+1, moves+1, dp)) % MOD;
        return dp[moves][row][col] = paths;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp (maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return dp[maxMove][m][n] = findPaths(m, n, maxMove, startRow, startColumn, 0, dp);      
    }
};
//https://leetcode.com/problems/out-of-boundary-paths/