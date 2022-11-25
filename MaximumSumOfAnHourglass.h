class Solution {
private:
    void updateSumForRow(vector<vector<int>>& grid, int &sum, int &row) {
        sum = grid[row][1];
        for(int j=0; j<3; j++) 
            sum += grid[row-1][j] + grid[row+1][j]; 
    }
    
    void updateSumColumn(vector<vector<int>>& grid, int &sum, int &i, int &j) {
        sum -= grid[i-1][j-2] + grid[i+1][j-2] + grid[i][j-1]; 
        sum += grid[i-1][j+1] + grid[i+1][j+1] + grid[i][j]; 
    }
    
public:
    int maxSum(vector<vector<int>>& grid) {
        int sum_max = 0, cur, m = grid.size(), n = grid[0].size();
        
        for(int i=1; i<m-1; i++) 
            for(int j=1; j<n-1; j++) {
                if(j==1) 
                    updateSumForRow(grid, cur, i);
                else 
                    updateSumColumn(grid, cur, i, j);

                sum_max = max(sum_max, cur);
            }
        
        return sum_max;
    }
};
//https://leetcode.com/problems/maximum-sum-of-an-hourglass/