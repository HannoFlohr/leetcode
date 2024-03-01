class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int min_falling_sum = INT_MAX;

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(j==0)
                    matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j+1]);
                else if(j==n-1)
                    matrix[i][j] += min(matrix[i+1][j-1], matrix[i+1][j]);
                else
                    matrix[i][j] += min({matrix[i+1][j-1], matrix[i+1][j], matrix[i+1][j+1]});
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
//https://leetcode.com/problems/minimum-falling-path-sum/