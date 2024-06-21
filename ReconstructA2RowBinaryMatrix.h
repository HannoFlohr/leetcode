class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        const int n = colsum.size();

        //count 2's and sum up colsum to check if its possible to construct a matrix with these parameters
        int count2 = 0, sum = 0;
        for(int col : colsum) {
            sum += col;
            if(col == 2) {
                ++count2;
            }
        }
        //check
        if(sum != upper+lower || lower < count2 || upper < count2) {
            return {};
        }

        //construct
        vector<vector<int>> grid (2, vector<int>(n,0));
        for(int i = 0; i < n; ++i) {
            if(colsum[i] == 2) {
                grid[0][i] = 1;
                grid[1][i] = 1;
                --upper;
                --lower;
            }
            else if(colsum[i] == 1) {
                if(upper > lower) {
                    grid[0][i] = 1;
                    --upper;
                }
                else {
                    grid[1][i] = 1;
                    --lower;
                }
            }
        }

        return grid;
    }
};
//https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/