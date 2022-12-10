class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1; //start comparing at top right corner

        while(x < m && y >= 0) {
            if(matrix[x][y] == target)
                return true;

            //if value in current cell is greater than the target: target can be in a lower column
            //if value in current cell is lower than the target: target can be in a higher row
            matrix[x][y] > target ? y-- : x++;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/search-a-2d-matrix-ii/