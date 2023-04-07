class Solution {
private: 
    void dfs(vector<vector<int>>& grid, const int& x, const int& y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
            return;

        grid[x][y] = 0;

        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1)
                    dfs(grid, i, j);

        return accumulate(grid.begin(), grid.end(), 0, [](int sum, auto& row){
                return sum + accumulate(row.begin(), row.end(), 0); });
    }
};
//https://leetcode.com/problems/number-of-enclaves/