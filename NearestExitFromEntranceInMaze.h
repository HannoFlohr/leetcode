class Solution {
private:
    const vector<vector<int>> moves ={{0,-1},{0,1},{-1,0},{1,0}};
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int distance = 1, i, j, x, y, qsize, m = maze.size(), n = maze[0].size();
        
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
		//BFS starting from entrance
        while(!q.empty()) {
            qsize = q.size();
            
			//visit adjacent cell if not a wall or visited before
            for(int k=0; k<qsize; k++) {
                i = q.front().first; 
                j = q.front().second;
                q.pop();
                
                for(auto &move : moves) {
                    x = i + move[0];
                    y = j + move[1];
                    
                    if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '+')
                        continue;
                    
                    if(x == 0 || x == m-1 || y == 0 || y == n-1)
                        return distance;
                    
                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            
            distance++;
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/