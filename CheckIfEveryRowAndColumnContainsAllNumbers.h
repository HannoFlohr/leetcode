class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            bitset<101> row, col; 
            
            for(int j=0; j<matrix[0].size(); j++) 
                row[matrix[i][j]] = 1, col[matrix[j][i]] = 1;
            
            if( min(row.count(), col.count() ) < matrix.size() )
                return false;
        }
        
        return true;
    }
};
//https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/