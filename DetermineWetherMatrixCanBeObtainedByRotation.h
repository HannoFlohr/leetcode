class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n  = mat.size();
        vector<bool> compare (4,true);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] != target[i][j]) 
                    compare[0] = false;
                if(mat[i][j] != target[n-j-1][i]) 
                    compare[1] = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) 
                    compare[2] = false;
                if(mat[i][j] != target[j][n-i-1]) 
                    compare[3] = false;
            }
        }

        return compare[0] || compare[1] || compare[2] || compare[3];
    }
};
//https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/