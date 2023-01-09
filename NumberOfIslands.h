class Solution {
private:
    int _m, _n;
    const vector<vector<int>> adjacent {{-1,0},{1,0},{0,-1},{0,1}};

    bool inBounds(const int& x, const int& y) {
        return x >= 0 && x < _m && y >= 0 && y < _n;
    }

    void markIsland(vector<vector<char>>& grid, int x, int y) {
        if( !inBounds(x, y) || grid[x][y] != '1' ) return;
        
        grid[x][y] = 'X';

        for(int dir = 0; dir < 4; dir++) 
            markIsland(grid, x + adjacent[dir][0], y + adjacent[dir][1]);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int number_of_islands = 0;

        _m = grid.size();
        _n = grid[0].size(); 

        for(int i = 0; i < _m; i++) {
            for(int j = 0; j < _n; j++) {
                if(grid[i][j] != '1') continue;

                number_of_islands++;
                markIsland(grid, i, j);
            }
        }

        return number_of_islands;
    }
};
//https://leetcode.com/problems/number-of-islands/