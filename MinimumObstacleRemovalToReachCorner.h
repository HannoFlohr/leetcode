class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        const int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        visited[0][0] = true;
        vector<vector<int>> distances (m, vector<int>(n, INT_MAX));    
        distances[0][0] = 0;
        deque<pair<int,int>> q;
        q.push_front({0, 0});

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop_front();

            for(auto [dx,dy] : directions) {
                int next_x = x+dx, next_y = y+dy;
                if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y])
                    continue;

                visited[next_x][next_y] = true;
                distances[next_x][next_y] = distances[x][y] + grid[next_x][next_y];
                if(grid[next_x][next_y] == 1)
                    q.push_back({next_x, next_y});
                else
                    q.push_front({next_x, next_y});
            }
        }

        return distances[m-1][n-1];
    }
};
//https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/