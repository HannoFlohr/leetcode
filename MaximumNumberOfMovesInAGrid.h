class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cur;
        vector<int> moves_next_col (m, 0);

        for(int col = n-2; col >= 0; col--) {
            vector<int> moves_this_col (m, 0);

            for(int row = 0; row < m; row++) {
                cur = grid[row][col];

                if(row-1 >= 0 && grid[row-1][col+1] > cur) {
                    moves_this_col[row] = max(moves_this_col[row], 1+moves_next_col[row-1]); }
                if(grid[row][col+1] > cur)
                    moves_this_col[row] = max(moves_this_col[row], 1+moves_next_col[row]);
                if(row+1 < m && grid[row+1][col+1] > cur)
                    moves_this_col[row] = max(moves_this_col[row], 1+moves_next_col[row+1]);
            }

            moves_next_col = moves_this_col;
        }

        return *max_element(moves_next_col.begin(), moves_next_col.end());
    }
};
//https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/