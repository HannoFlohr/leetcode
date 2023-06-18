class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int n = grid.size();
        map<vector<int>, int> rows;

        for(const auto& row : grid)
            rows[row]++;

        int result = 0;
        for(int i = 0; i < n; ++i) {
            vector<int> col (n);
            for(int j = 0; j < n; ++j)
                col[j] = grid[j][i];
        
            result += rows[col];
        }

        return result;
    }
};
//https://leetcode.com/problems/equal-row-and-column-pairs/