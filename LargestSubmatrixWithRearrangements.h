class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), largest = 0;
        vector<int> height (n,0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    ++height[j];
                else
                    height[j] = 0;
            }

            vector<int> sorted_height = height;
            sort(sorted_height.begin(), sorted_height.end());

            for(int j = 0; j < n; j++) {
                largest = max(largest, sorted_height[j] * (n-j));
            }
        }

        return largest;
    }
};
//https://leetcode.com/problems/largest-submatrix-with-rearrangements/