class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size();
        const vector<pair<int,int>> directions {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        int moves = 0, keys_needed = 0;
        vector<vector<vector<bool>>> visited (m, vector<vector<bool>>(n, vector<bool>(64, false))); //keys <= 6; bitmap using 6 bits
        queue<tuple<int,int,int>> q; //<position x/y, how many keys>

        //find start and number of keys needed
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '@') {
                    q.push({i, j, 0});
                    visited[i][j][0] = true;
                } 
                if(grid[i][j] >= 'A' && grid[i][j] <= 'F')
                    keys_needed++;
            }
        } 

        while(!q.empty()) {
            int qsize = q.size();

            while(qsize-- > 0) {
                auto [pos_x,pos_y,keys_carried] = q.front();
                q.pop();

                if(keys_carried == ((1<<keys_needed)-1)) //all keys were found
                    return moves;

                for(const auto& [dx,dy] : directions) { //check all possible moves
                    int next_x = pos_x+dx, next_y = pos_y+dy, keys = keys_carried;

                    //bounds and not wall?
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || grid[next_x][next_y] == '#')
                        continue;
                    //if cell is key, update bitmapped keys carried
                    if(grid[next_x][next_y] >= 'a' && grid[next_x][next_y] <= 'f')
                        keys = keys | (1<<(grid[next_x][next_y]-'a'));
                    //if lock is found and corresponding key not available -> can't move in this direction 
                    else if(grid[next_x][next_y] >= 'A' && grid[next_x][next_y] <= 'F')
                        if(!(keys_carried & (1<<(grid[next_x][next_y]-'A'))))
                            continue;

                    //check if visited before, else add to queue
                    if(!visited[next_x][next_y][keys]) {
                        visited[next_x][next_y][keys] = true;
                        q.push({next_x,next_y,keys});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};
//https://leetcode.com/problems/shortest-path-to-get-all-keys/