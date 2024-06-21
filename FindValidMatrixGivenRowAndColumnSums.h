class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> grid (m, vector<int>(n,0));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                grid[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= grid[i][j];
                colSum[j] -= grid[i][j];
            }
        }

        return grid;
    }
};
//https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/