class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(); 
        int low = 0, high = m * n - 1, mid, mid_value;
        
        while(low <= high) {
            mid = low + (high - low) / 2; 
            mid_value = matrix[mid / n][mid % n];
            
            if(mid_value == target) return true;
            else if(mid_value < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/search-a-2d-matrix/