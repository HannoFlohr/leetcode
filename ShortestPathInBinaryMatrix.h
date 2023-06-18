class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int rows = grid.size()-1, cols = grid[0].size()-1;
        if(grid[0][0] == 1 || grid[rows][cols] == 1)
            return -1;        
        const vector<pair<int,int>> directions = {{1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,-1}, {-1, 1}};

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == rows && y == cols)
                return grid[x][y];

            for(const auto& [dx, dy] : directions) {
                int newx = x+dx, newy = y+dy;
                if(newx >= 0 && newx <= rows && newy >= 0 && newy <= cols && grid[newx][newy] == 0) {
                    q.push({newx,newy});
                    grid[newx][newy] = grid[x][y]+1;
                }
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/shortest-path-in-binary-matrix/