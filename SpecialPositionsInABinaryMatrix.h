class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> count_row (m,0);
        vector<int> count_col (n,0);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] != 1)
                    continue;
                count_row[i]++;
                count_col[j]++;
            }
        }

        int special = 0;
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j) 
                if(mat[i][j] == 1 && (count_row[i] == 1 && count_col[j] == 1)) 
                    special++;

        return special;
    }
};
//https://leetcode.com/problems/special-positions-in-a-binary-matrix/