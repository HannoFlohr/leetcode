class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> m;
        vector<int> result;

        for(int row = 0; row < mat.size(); row++) {
            for(int col = 0; col < mat[row].size(); col++) {
                m[row+col].push_back(mat[row][col]);
            }
        }

        for(const auto& [key,values] : m) {
            if(key%2 == 0)
                for(int i = values.size()-1; i >= 0; i--) 
                    result.push_back(values[i]);
            else
                for(int i = 0; i < values.size(); i++) 
                    result.push_back(values[i]);
        }

        return result;
    }
};
//https://leetcode.com/problems/diagonal-traverse/