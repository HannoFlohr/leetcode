class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat (m, vector<int>(n, 0));

        for(const auto& op : indices) {
            for(int i = 0; i < n; ++i) {
                ++mat[op[0]][i];
            }
            for(int i = 0; i < m; ++i) {
                ++mat[i][op[1]];
            }
        }

        int odd = 0;
        for(const auto& row : mat) {
            for(int col : row) {
                if(col % 2 == 1)
                    ++odd;
            }
        }

        return odd;
    }
};
//https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/