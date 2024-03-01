class Solution {
private:
    int dfs(const vector<vector<int>>& grid, int m, int n, int row, int col1, int col2, vector<vector<vector<int>>>& dp) {
        if(row == m) 
            return 0;
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int count = 0;
        for(int new_col1 = col1-1; new_col1 <= col1+1; ++new_col1) {
            for(int new_col2 = col2-1; new_col2 <= col2+1; ++new_col2) {
                if(new_col1 >= 0 && new_col1 < n && new_col2 >= 0 && new_col2 < n) {
                    count = max(count, dfs(grid,m,n,row+1,new_col1,new_col2,dp)); 
                }
            }
        }
        
        int cherries = (col1 == col2) ? grid[row][col1] : grid[row][col1]+grid[row][col2];
        return dp[row][col1][col2] = count + cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp (70, vector<vector<int>>(70, vector<int>(70, -1))); 
        return dfs(grid, grid.size(), grid[0].size(), 0, 0, grid[0].size() - 1, dp);
    }
};
//https://leetcode.com/problems/cherry-pickup-ii/