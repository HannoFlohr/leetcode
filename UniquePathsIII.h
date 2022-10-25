class Solution {
private: 
    int m, n, emptyCells = 1, result = 0;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int visited=0) { 
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y] == -1) return;
        
        //if end point is reached, check if all empty cells were visited
        if(grid[x][y] == 2) { 
            if(visited == emptyCells) 
                result++;
            return;
        }
        
        grid[x][y] = -1; //mark current position as obstacle as it was already walked over
        
        //search in all four direction
        dfs(grid, x-1, y, visited+1);
        dfs(grid, x+1, y, visited+1);
        dfs(grid, x, y-1, visited+1);
        dfs(grid, x, y+1, visited+1);
        
        grid[x][y] = 0; //backtrack marking
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y; 
        m=grid.size(), n=grid[0].size(); 

        //find start position and count empty cells
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) x = i, y = j;
                if(grid[i][j] == 0) emptyCells++; 
            }
        }

        dfs(grid, x, y);
        
        return result;
    }
};
//https://leetcode.com/problems/unique-paths-iii/