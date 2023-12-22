class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        k %= n; 

        if(k == 0)
            return true;

        for(vector<int>& row : mat) {
            for(int col = 0; col < n; col++) {
                if(row[col] != row[(col+k)%n]) {
                    return false;
                }
            }
        }

        return true;
    }
};
//https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/