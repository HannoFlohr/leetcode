class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const vector<pair<int,int>> directions {{-1,0},{1,0},{0,-1},{0,1}};
        const int n = grid.size();
        int height, neighbor, n_row, n_col, surfaces = n*n*2;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) {
                    surfaces -= 2;
                    continue;
                }

                height = grid[row][col];
                
                for(auto [dr,dc] : directions) {
                    n_row = row+dr, n_col = col+dc;
                    if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < n) {
                        neighbor = grid[n_row][n_col];
                    }
                    else {
                        neighbor = 0;
                    }

                    if(neighbor < height) {
                        surfaces += (height-neighbor);
                    }
                }
            }
        }

        return surfaces;
    }
};
//https://leetcode.com/problems/surface-area-of-3d-shapes/

/*
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int n = grid.size();
        int surfaces = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) {
                    continue;
                }

                surfaces += grid[row][col] * 4 + 2;
                if(row > 0) {
                    surfaces -= min(grid[row][col], grid[row-1][col]) * 2;
                }
                if(col > 0) {
                    surfaces -= min(grid[row][col], grid[row][col-1]) * 2;
                }
            }
        }

        return surfaces;
    }
};
*/