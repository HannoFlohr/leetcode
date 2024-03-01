class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> min_row (m), max_col (n);

        for(int row = 0; row < m; ++row) {
            min_row[row] = *min_element(matrix[row].begin(), matrix[row].end());
        }

        for(int col = 0; col < n; ++col) {
            int max_ele = 0;
            for(int row = 0; row < m; ++row) {
                max_ele = max(max_ele, matrix[row][col]);
            }
            max_col[col] = max_ele;
        }

        vector<int> lucky_numbers;
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                int x = matrix[row][col];
                if(x == min_row[row] && x == max_col[col]) {
                    lucky_numbers.push_back(x);
                }
            }
        }
        return lucky_numbers;
    }
};
//https://leetcode.com/problems/lucky-numbers-in-a-matrix/