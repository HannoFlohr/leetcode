class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size(); 

        for(auto& row : grid) {
            sort(row.begin(), row.end());
        }

        vector<int> col_max (n, 0);
        for(const vector<int>& row : grid) {
            for(int i = 0; i < n; ++i) {
                col_max[i] = max(col_max[i], row[i]);
            }
        }

        return accumulate(col_max.begin(), col_max.end(), 0);
    }
};
//https://leetcode.com/problems/delete-greatest-value-in-each-row/