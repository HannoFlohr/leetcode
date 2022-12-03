class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        const int m = mat.size(), n = mat[0].size();
        
        if(m == r && n == c || r * c != m * n) return mat;
        
        vector<vector<int>> a (r, vector<int>(c));
        for(int i=0; i<m*n; i++) 
            a[i / c][i % c] = mat[i / n][i % n];
        
        return a;
    }
};
//https://leetcode.com/problems/reshape-the-matrix/