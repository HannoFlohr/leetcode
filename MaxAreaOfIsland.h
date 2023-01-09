class Solution {
private:
    int _m, _n;
    const vector<vector<int>> adjacent {{-1,0},{1,0},{0,-1},{0,1}};

    bool inBounds(const int& x, const int& y) {
        return x >= 0 && x < _m && y >= 0 && y < _n;
    }

    void sizeOfIsland(vector<vector<int>>& grid, int i, int j, int& area) { 
        if( !inBounds(i, j) || grid[i][j] != 1) return;

        grid[i][j] = 0;
        area++;

        for(int dir = 0; dir < 4; dir++) 
            sizeOfIsland(grid, i + adjacent[dir][0], j + adjacent[dir][1], area);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area, max_area = 0;
        _m = grid.size(), _n = grid[0].size();

        for(int i=0; i<_m; i++) {
            for(int j=0; j<_n; j++) {
                if(grid[i][j] != 1) continue;

                area = 0;
                sizeOfIsland(grid, i, j, area);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};
//https://leetcode.com/problems/max-area-of-island/