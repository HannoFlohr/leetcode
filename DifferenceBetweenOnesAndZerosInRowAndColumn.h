class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> ones_row (m,0), ones_col(n,0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ones_row[i]++;
                    ones_col[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = ones_row[i] + ones_col[j] - (m-ones_row[i]) - (n-ones_col[j]);
            }
        }

        return grid;
    }
};
//https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/