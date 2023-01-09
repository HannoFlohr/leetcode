class Solution {
private:
    const vector<vector<int>> adjacent {{-1,0},{1,0},{0,-1},{0,1}};
    int _m, _n;

    bool inBounds(const int& x, const int& y) {
        return x >= 0 && x < _m && y >= 0 && y < _n;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        _m = grid.size(), _n = grid[0].size();
        int minutes = -1, fresh = 0, qsize, row, col;
        
        queue<pair<int,int>> q;
        for(int i=0; i<_m; i++) {
            for(int j=0; j<_n; j++) {
                if(grid[i][j] == 1) 
                    fresh++;
                else if(grid[i][j] == 2) 
                    q.push({i,j});
            }
        }

        if(q.empty()) return fresh > 0 ? -1 : 0;

        while(!q.empty()) {
            qsize = q.size();
            while(qsize--) {
                auto [x, y] = q.front();
                q.pop();

                for(int dir=0; dir<4; dir++) {
                    row = x + adjacent[dir][0];
                    col = y + adjacent[dir][1];

                    if(inBounds(row, col) && grid[row][col]==1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        return fresh > 0 ? -1 : minutes;
    }
};
//https://leetcode.com/problems/rotting-oranges/