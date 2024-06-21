class Solution {
private:
    int getBlockSum(const vector<vector<int>>& mat, int m, int n, int x, int y, int k) {
        int sum = 0;
        for(int row = max(0, x-k); row < min(m, x+k+1); ++row) {
            for(int col = max(0, y-k); col < min(n, y+k+1); ++col) {
                sum += mat[row][col];
            }
        }
        return sum;
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> block_sum (m, vector<int>(n, 0));
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                block_sum[row][col] = getBlockSum(mat, m, n, row, col, k);
            }
        }
        return block_sum;
    }
};
//https://leetcode.com/problems/matrix-block-sum/