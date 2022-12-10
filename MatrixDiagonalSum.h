class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();
        
        for(int i=0; i<n; i++) 
            sum += mat[i][i] + (i == n-i-1 ? 0 : mat[n-1-i][i]);   
        
        return sum;
    }
};
//https://leetcode.com/problems/matrix-diagonal-sum/