class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        bool row = false, column = false;
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if(matrix[i][j] == 0) {
                    if(i==0) row = true;
                    if(j==0) column = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
        
        if(row)
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        if(column)
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
    }
};
//

/* O(m+n) space solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<bool> rows (m, false);
        vector<bool> columns (n, false);
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    columns[j] = true;
                }
        
        for(int i=0; i<m; i++)
            if(rows[i])
                for(int j=0; j<n; j++)
                    matrix[i][j] = 0;
        
        for(int j=0; j<n; j++)
            if(columns[j])
                for(int i=0; i<m; i++)
                    matrix[i][j] = 0;
    }
};

*/