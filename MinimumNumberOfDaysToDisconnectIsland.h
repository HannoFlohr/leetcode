class Solution {
private:
    const vector<pair<int,int>> directions {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void markIsland(const vector<vector<int>>& grid, int x, int y, int m, int n, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        for(auto [dx,dy] : directions) {
            int goto_x = x+dx, goto_y = y+dy;
            if(goto_x >= 0 && goto_x < m && goto_y >= 0 && goto_y < n && !visited[goto_x][goto_y] && grid[goto_x][goto_y] == 1) {
                markIsland(grid, goto_x, goto_y, m, n, visited);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int islands = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    markIsland(grid, i, j, grid.size(), grid[0].size(), visited);
                    ++islands;
                }
            }
        }

        return islands;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int islands = countIslands(grid);

        //already disconnected
        if(islands == 0 || islands > 1) {
            return 0;
        }
        //check for 1 step disconnect
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    islands = countIslands(grid);
                    if(islands > 1 || islands == 0) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        //otherwise always doable in 2 steps
        return 2;
    }
};
//https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/