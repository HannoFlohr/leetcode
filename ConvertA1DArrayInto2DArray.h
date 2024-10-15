class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) {
            return {};
        }

        vector<vector<int>> v (m, vector<int>(n));
        int x = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                v[i][j] = original[x++];
            }
        }
        return v;
    }
};
//https://leetcode.com/problems/convert-1d-array-into-2d-array/