class Solution {
private:
    const vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int _m, _n;

    bool inBounds(int x, int y) {
        return (x >= 0 && x < _m && y >= 0 && y < _n);
    }

    void markGuardedCells(int x, int y, int m, int n, vector<vector<char>>& grid) { 
        for(auto [dx,dy] : directions) {
            int next_x = x+dx, next_y = y+dy;
            while(inBounds(next_x, next_y) && grid[next_x][next_y] != 'w' && grid[next_x][next_y] != 'g') {
                grid[next_x][next_y] = '-';
                next_x += dx;
                next_y += dy;
            }    
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        _m = m, _n = n;
        vector<vector<char>> grid (m, vector<char>(n,'+')); 

        //mark all walls in grid
        for(vector<int>& wall : walls)
            grid[wall[0]][wall[1]] = 'w';  
        //mark all guards in grid
        for(vector<int>& guard : guards) 
            grid[guard[0]][guard[1]] = 'g';    
        //mark all cells visible by any of the guards
        for(vector<int>& guard : guards) 
            markGuardedCells(guard[0], guard[1], m, n, grid);

        //count unguarded cells
        int count = 0;
        for(vector<char>& row : grid) {
            for(char c : row) {
                if(c == '+') 
                    ++count;
            }
        }     

        return count;
    }
};
//https://leetcode.com/problems/count-unguarded-cells-in-the-grid/