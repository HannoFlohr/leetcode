class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, n = grid[0].size(), row = 0, column = n-1;

        while(row < grid.size()) {
            //for each row: check from right how many negative elements (lower rows: at least as many negative columns)
            while(column >= 0 && grid[row][column] < 0) 
                column--;

            count += n-1 - column;
            row++;
        }

        return count;
    }
};
//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

/* O(n log m)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        //for each row: use upper bound from right to find non negative 
        for(const vector<int>& row : grid) 
            count += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();

        return count;
    }
};

*/