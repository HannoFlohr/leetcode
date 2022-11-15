class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue;
                
                if(i==0   || (i>0   && !grid[i-1][j]) ) perimeter++;
                if(j==0   || (j>0   && !grid[i][j-1]) ) perimeter++;
                if(i==m-1 || (i<m-1 && !grid[i+1][j]) ) perimeter++;
                if(j==n-1 || (j<n-1 && !grid[i][j+1]) ) perimeter++;
            }
        
        return perimeter;
    }
};
//https://leetcode.com/problems/island-perimeter/