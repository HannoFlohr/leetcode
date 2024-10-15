class Solution {
private:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        vector<bool> numbers (10, false);
        vector<int> row_sum (3,0), col_sum (3,0);
        
        //set numbers and row and col sums
        for(int i = row-1; i <= row+1; ++i) {
            for(int j = col-1; j <= col+1; ++j) {
                int x = grid[i][j];
                if(x < 1 || x > 9) {
                    return false;
                }        
                row_sum[i-row+1] += x;
                col_sum[j-col+1] += x;
                numbers[x] = true;
            }
        }

        //check if all numbers from 1 to 9 are present
        for(int i = 1; i <= 9; ++i) {
            if(numbers[i] == false) {
                return false;
            }
        }
        //check if row and col sums are all 15
        for(int sum : row_sum) {
            if(sum != 15) {
                return false;
            }
        }
        for(int sum : col_sum) {
            if(sum != 15) {
                return false;
            }
        }
        //check if diagonals are 15 as well (5 in middle)
        return grid[row-1][col-1] + grid[row+1][col+1] == 10 && grid[row+1][col-1] + grid[row-1][col+1];
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(m < 3 || n < 3) {
            return 0;
        }

        int magic_squares = 0;
        //loop through grid to find possible candidates for magic squares
        //magic squares must have a 5 in the middle
        for(int row = 1; row < m-1; ++row) {
            for(int col = 1; col < n-1; ++col) {
                if(grid[row][col] == 5 && isMagicSquare(grid, row, col)) {
                    ++magic_squares;
                }
            }
        }

        return magic_squares;
    }
};
//https://leetcode.com/problems/magic-squares-in-grid/