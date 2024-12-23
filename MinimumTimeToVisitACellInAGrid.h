class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        //check if the start is blocked already - necesary for later step of jumping back and forth between two cells
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        const int m = grid.size(), n = grid[0].size();
        const vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});

        while(!q.empty()) {
            int time = q.top()[0], x = q.top()[1], y = q.top()[2];
            q.pop();

            //bottom-right corner reached
            if(x == m-1 && y == n-1)
                return time;

            if(visited[x][y]) 
                continue;
            visited[x][y] = true;

            //goto neighbors if possible
            for(auto [dx,dy] : directions) {
                int next_x = x+dx, next_y = y+dy;
                if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y])
                    continue;
                
                //wait time required to reach neighbor cell
                //if time at neighbor cell is > time+1, jump between the last two visited cells until time is reached
                int wait = (grid[next_x][next_y] - time) % 2 == 0;
                q.push({max(grid[next_x][next_y] + wait, time+1), next_x, next_y});
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/