class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), -1));
        
        //queue stores x, y, length of cur path, obstacles that can be removed still
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()) {
            auto v = q.front();
            int x = v[0], y = v[1];
            q.pop();
            
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
                continue;
            
            if(x == grid.size()-1 && y==grid[0].size()-1)
                return v[2];
            
            if(grid[x][y] == 1) {
                if(v[3] > 0)
                    v[3]--;
                else
                    continue;
            }
            
            if(visited[x][y] != -1 && visited[x][y] >= v[3])
                continue;
            visited[x][y] = v[3];
            
            q.push({x+1,    y,      v[2]+1, v[3]});
            q.push({x,      y+1,    v[2]+1, v[3]});
            q.push({x-1,    y,      v[2]+1, v[3]});
            q.push({x,      y-1,    v[2]+1, v[3]});
        }
        return -1;
    }
};
//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/