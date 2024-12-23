class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), count_negative = 0, min_number = INT_MAX;
        long long sum = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) 
                    ++count_negative;
                min_number = min(min_number, abs(matrix[i][j]));
            }
        }

        if(count_negative % 2 == 0)
            return sum;
        return sum - 2 * min_number;
    }
};
//https://leetcode.com/problems/maximum-matrix-sum/