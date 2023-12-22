class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> m;
        vector<int> result;

        for(int row = 0; row < nums.size(); row++) {
            for(int col = 0; col < nums[row].size(); col++) {
                m[row+col].push_back(nums[row][col]);
            }
        }

        for(const auto& [key,values] : m) {
            for(int i = values.size()-1; i >= 0; i--) {
                result.push_back(values[i]);
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/diagonal-traverse-ii/

/* 54/46 TC passed; TLE after

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = 0;
        for(int i = 0; i < m; i++) {
            n = max(n, (int)nums[i].size());
        }

        vector<int> result;
        for(int start_row = 0; start_row < m; start_row++) {
            for(int row = start_row, col = 0; row >= 0 && col < n; --row, ++col) {
                if(col < nums[row].size())
                    result.push_back(nums[row][col]);
            }
        }
        for(int start_col = 1; start_col < n; start_col++) {
            for(int row = m-1, col = start_col; row >= 0 && col < n; --row, ++col) {
                if(col < nums[row].size())
                    result.push_back(nums[row][col]);
            }
        }

        return result;
    }
};
*/