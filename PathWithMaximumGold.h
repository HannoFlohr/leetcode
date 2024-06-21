class Solution {
private:
    const vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int findMaximumPath(vector<vector<int>>& grid, int m, int n, int x, int y) { 
        //check bounds and if the cell is 0
        if(x < 0 || x == m || y < 0 || y == n || grid[x][y] == 0) {
            return 0;
        }

        const int original_cell_value = grid[x][y];
        //change value of cell to 0, so it wont be visited again
        grid[x][y] = 0;
        int gold = original_cell_value;
        //try to path in all four directions
        for(auto [dx,dy] : directions) {
            gold = max(gold, original_cell_value + findMaximumPath(grid, m, n, x+dx, y+dy));
        }
        //backtrack to old cell value
        grid[x][y] = original_cell_value;

        return gold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), max_gold = 0;   
        //check all start points
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                //skip if 0
                if(grid[i][j] == 0) {
                    continue;
                }

                max_gold = max(max_gold, findMaximumPath(grid, m, n, i, j));
            }
        }
    
        return max_gold;
    }   
};
//https://leetcode.com/problems/path-with-maximum-gold/