class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int n = grid.size();
        const vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> distance (n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        //put all thieve positions in queue
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                if(grid[row][col] == 1) {
                    q.push({row,col});
                    distance[row][col] = 0;
                }
            }
        }

        //calculate minimum distance to any thief for each cell in grid
        while(!q.empty()) {
            auto [row,col] = q.front();
            q.pop();

            for(auto [dr,dc] : directions) {
                int nextrow = row+dr, nextcol = col+dc; 
                if(nextrow >= 0 && nextrow < n && nextcol >= 0 && nextcol < n && distance[nextrow][nextcol] == INT_MAX) {
                    distance[nextrow][nextcol] = distance[row][col] + 1;
                    q.push({nextrow,nextcol});
                }
            }
        }

        //find path with max safeness 
        vector<vector<int>> max_safeness (n, vector<int>(n,-1));
        max_safeness[0][0] = distance[0][0];
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({distance[0][0], {0,0}});

        while(!pq.empty()) {
            int dist = pq.top().first, row = pq.top().second.first, col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1) {
                return dist;
            }

            for(auto [dr,dc] : directions) {
                int nextrow = row+dr, nextcol = col+dc; 
                if(nextrow >= 0 && nextrow < n && nextcol >= 0 && nextcol < n) {
                    int new_safeness = min(dist, distance[nextrow][nextcol]);
                    if(new_safeness > max_safeness[nextrow][nextcol]) {
                        max_safeness[nextrow][nextcol] = new_safeness;
                        pq.push({new_safeness, {nextrow,nextcol}});
                    }
                }
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/find-the-safest-path-in-a-grid/