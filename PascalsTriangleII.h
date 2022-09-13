class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> p (rowIndex+1);
        
        for(int i=0; i<=rowIndex; i++) { 
            p[i].resize(i+1);
            p[i][0] = p[i][i] = 1;
            
            for(int j=1; j<i; j++) 
                p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
                
        return p[rowIndex];
    }
};
https://leetcode.com/problems/pascals-triangle-ii/