class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> result;
        int col1, col2;
        
        for(int j=0; j<n; j++) {
            col1 = j; 
            for(int i=0; i<m; i++) {
                col2 = col1 + grid[i][col1];
                
                //if the ball wants to move from one column to another, 
                //the grid values for these columns must be the same (grid[i][j1] == grid[i][j2])  
                if(col2 < 0 || col2 >= n || grid[i][col2] != grid[i][col1]) {
                    col1 = -1;
                    break;
                }
                
                col1 = col2;
            }
            
            result.push_back(col1);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/where-will-the-ball-fall/