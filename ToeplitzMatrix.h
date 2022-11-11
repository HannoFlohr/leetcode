class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size()-1; i++)
            for(int j=0; j<matrix[0].size()-1; j++)
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
        return true;
    }
};
//https://leetcode.com/problems/toeplitz-matrix/

/*
class Solution {
private:
    int m, n;
    
    bool isDiagonalWithSameValue(vector<vector<int>>& matrix, int start_i, int start_j) {
        //int first = matrix[start_i][start_j];
        for(int i=start_i+1, j=start_j+1; i<m && j<n; i++, j++)
            if(matrix[start_i][start_j] != matrix[i][j]) 
                return false;
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        for(int i=0; i<m; i++)
            if(!isDiagonalWithSameValue(matrix, i, 0))
               return false;
    
        for(int j=1; j<n; j++)
            if(!isDiagonalWithSameValue(matrix, 0, j))
               return false;
               
        return true;
    }
};
*/