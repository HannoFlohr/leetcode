class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const vector<vector<int>> adjacent {{0,0,-1,1},{-1,1,0,0}};
        const int n = grid.size();
        queue<pair<int,int>> q, q_new;
        int steps = 0, qsize;

        for(size_t i=0; i<n; i++) {
            for(size_t j=0; j<n; j++) {
                if(grid[i][j] != 1) continue; 
                
                for(size_t a=0; a<4; a++)
                    q.push({i+adjacent[0][a], j+adjacent[1][a]});
            }
        }

        while(!q.empty()) {
            steps++;
            qsize = q.size();

            while(qsize--) {
                auto [x,y] = q.front();
                q.pop();

                if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 0) continue;

                grid[x][y] = steps;
                for(size_t a=0; a<4; a++)
                    q.push({x+adjacent[0][a], y+adjacent[1][a]});
            }
        }
        
        return steps == 1 ? -1 : steps-1;
    }
};
//https://leetcode.com/problems/as-far-from-land-as-possible/