class Solution {
private: 
    int isSubisland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n) {
        if(i < 0 || i == m || j < 0 || j == n || grid2[i][j] == 0) 
            return 1;
        
        grid2[i][j] = 0;
        int result = 1;
        result &= isSubisland(grid1, grid2, i-1, j, m, n);
        result &= isSubisland(grid1, grid2, i+1, j, m, n);
        result &= isSubisland(grid1, grid2, i, j-1, m, n);
        result &= isSubisland(grid1, grid2, i, j+1, m, n);
        return result & grid1[i][j];
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), subislands = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid2[i][j] == 1) 
                    subislands += isSubisland(grid1, grid2, i, j, m, n);
            }
        }

        return subislands;
    }
};
//https://leetcode.com/problems/count-sub-islands/