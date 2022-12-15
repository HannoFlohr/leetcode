class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        int left_column = 0, mid_column, right_column = n-1, max_in_row;
        bool left_neighbor_greater, right_neighbor_greater;

        while(left_column <= right_column) {
            mid_column = left_column + (right_column - left_column) / 2;
            max_in_row = 0;

            //find the max element for the current middle column
            for(int row=0; row<m; row++)
                if(mat[row][mid_column] > mat[max_in_row][mid_column])
                    max_in_row = row;

            //check if left/right neighbors of the max element are greater than the max element
            left_neighbor_greater  = mid_column-1 >= left_column && mat[max_in_row][mid_column-1] > mat[max_in_row][mid_column];
            right_neighbor_greater = mid_column+1 <= right_column && mat[max_in_row][mid_column+1] > mat[max_in_row][mid_column];
            
            if(!left_neighbor_greater && !right_neighbor_greater) //peak found
                return {max_in_row, mid_column};
            else if(left_neighbor_greater)
                right_column = mid_column - 1;
            else
                left_column = mid_column + 1;
        }

        return {-1,-1};
    }
};
//https://leetcode.com/problems/find-a-peak-element-ii/

/*
using binary search on the column
for the middle column find the max row element
compare that element to its left/right neighbors 
- if middle column max element is greater than both neighbors we found a peak
- else check columns to left or right
*/