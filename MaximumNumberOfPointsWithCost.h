class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size(), n = points[0].size();
        vector<long long> previous_rows (n,0);

        for(int i = 0; i < n; ++i) {
            previous_rows[i] = points[0][i];
        }

        for(int row = 0; row < m-1; ++row) {
            vector<long long> max_from_left (n,0), max_from_right (n,0), cur (n,0);
            max_from_left[0] = previous_rows[0];
            max_from_right[n-1] = previous_rows[n-1];

            for(int col = 1; col < n; ++col) {
                max_from_left[col] = max(max_from_left[col-1]-1, previous_rows[col]);
            }
            for(int col = n-2; col >= 0; --col) {
                max_from_right[col] = max(max_from_right[col+1]-1, previous_rows[col]);
            }
            for(int col = 0; col < n; ++col) {
                cur[col] = points[row+1][col] + max(max_from_left[col], max_from_right[col]);
            }

            previous_rows = cur;
        }

        return *max_element(previous_rows.begin(), previous_rows.end());
    }
};
//https://leetcode.com/problems/maximum-number-of-points-with-cost/	