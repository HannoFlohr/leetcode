class Solution {
private:
    int getMaxLocal(vector<vector<int>> &grid, int row, int col) {
        int localmax=0;
        for(int i=row-1; i<=row+1; i++)
            for(int j=col-1; j<=col+1; j++)
                localmax = max(localmax, grid[i][j]);
        return localmax;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> maxLocal (grid.size()-2, vector<int>(grid.size()-2));
        
        for(int i=1; i<grid.size()-1; i++)
            for(int j=1; j<grid[0].size()-1; j++) 
                maxLocal[i-1][j-1] = getMaxLocal(grid, i, j); 
    
        return maxLocal;
    }
};
//https://leetcode.com/problems/largest-local-values-in-a-matrix/