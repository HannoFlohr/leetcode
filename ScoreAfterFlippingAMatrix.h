class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        //for each row: if row[0] = 0 flip row
        for(vector<int>& row : grid) {
            if(row[0] == 1) {
                continue;
            }
            for(int i = 0; i < n; ++i) {
                row[i] = !row[i];
            }
        }
        //for(auto& row:grid) {for(auto col:row) {cout<<col<<" ";}cout<<endl;}cout<<endl;

        //for each column: if ones used in column is <= m/2 flip it
        for(int col = 1; col < n; ++col) {
            int ones = 0;
            for(int row = 0; row < m; ++row) {
                ones += grid[row][col];
            }
            if(ones*2 < m) {
                for(int row = 0; row < m; ++row) {
                    grid[row][col] = !grid[row][col];
                }
            }
        }
        //for(auto& row:grid) {for(auto col:row) {cout<<col<<" ";}cout<<endl;}cout<<endl;

        //sum up the score for all rows
        int score = 0;
        for(vector<int>& row : grid) {
            int value = 0;
            for(int col : row) {
                value = value * 2 + col;
            }
            score += value;
        }

        return score;
    }
};
//https://leetcode.com/problems/score-after-flipping-matrix/