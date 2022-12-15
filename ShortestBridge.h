class Solution {
private:
    int n;
    const vector<vector<int>> adjacent {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int,int>> q;

    void markIsland(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1) return;
        
        grid[i][j] = 2;
        q.push({i,j});

        for(auto &a : adjacent)
            markIsland(grid, i+a[0], j+a[1]);
    }

    void findIsland(vector<vector<int>>& grid) {
        int i, j;
        bool found = false;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++)
                if(grid[i][j] == 1) {
                    found = true;
                    break;
                }
            if(found) break;
        }

        markIsland(grid, i, j);
    }

    int findMinDistance(vector<vector<int>>& grid) {
        int i, j, x, y;

        while(!q.empty()) {
            i = q.front().first, j = q.front().second;
            q.pop();
            for(auto &a : adjacent) {
                x = i + a[0], y = j + a[1];

				//check bounds
                if(x<0 || y<0 || x>=n || y>=n) continue; 
            
				//other island was found, return distance
                if(grid[x][y] == 1)
                    return grid[i][j] - 2;
				//mark neighbor cell if still '0' and push on queue
                if(grid[x][y] == 0) {
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x,y});
                }
            }
        }

        return -1;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size(); 
        findIsland(grid);
        return findMinDistance(grid);
    }
};
//https://leetcode.com/problems/shortest-bridge/

/*
- look for the first island by looking for a '1' in the grid (void findIsland(..)) 
- mark all points belonging to the first island with a '2' and saving the points in a queue (void markIsland(..))
- than use the saved values to mark the neighbor cells with a '3', the neighbors of those with a '4' and so on until we encounter a neighbor with a '1'
	i.e. we found the minimum distance as value saved for current cell - 2
*/