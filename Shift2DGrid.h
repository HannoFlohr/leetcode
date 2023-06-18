class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> answer (m, vector<int>(n));
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
                answer[(i + (j+k)/n) % m][(j+k)%n] = grid[i][j];

        return answer;
    }
};
//https://leetcode.com/problems/shift-2d-grid/