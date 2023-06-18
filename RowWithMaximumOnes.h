class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ones, max_row = 0, max_ones = 0;

        for(int row = 0; row < mat.size(); ++row) {
            ones = 0;

            for(const auto &col : mat[row]) 
                if(col == 1)
                    ones++;

            if(ones > max_ones) 
                max_ones = ones, max_row = row;
        }

        return {max_row, max_ones};
    }
};
//https://leetcode.com/problems/row-with-maximum-ones/