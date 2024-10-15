class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), missing, repeated;
        vector<int> numbers (n*n+1, 0);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(++numbers[grid[i][j]] > 1)
                    repeated = grid[i][j];
            }
        }
        for(int i = 1; i <= n*n; ++i) {
            if(numbers[i] == 0) {
                missing = i;
                break;
            }
        }

        return {repeated, missing};
    }
};
//https://leetcode.com/problems/find-missing-and-repeated-values/