class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> T (n, vector<int>(m));

        for(int col = 0; col < n; col++) {
            for(int row = 0; row < m; row++) {
                T[col][row] = matrix[row][col];
            }
        }

        return T;
    }
};
//https://leetcode.com/problems/transpose-matrix/