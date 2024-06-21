class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) { 
        const int n = grid.size(); 
        int first, second, first_index = -1;

        for(int row = 0; row < n; ++row) {
            if(row != 0) {
                for(int col = 0; col < n; ++col) {
                    grid[row][col] += (col != first_index) ? first : second;
                }
            }

            first = INT_MAX;
            second = INT_MAX;

            for(int col = 0; col < n; ++col) {
                if(grid[row][col] < first) {
                    second = first;
                    first = grid[row][col];
                    first_index = col;
                }
                else if(grid[row][col] < second) {
                    second = grid[row][col];
                }
            }
        }

        return first;
    }
};
//https://leetcode.com/problems/minimum-falling-path-sum-ii/