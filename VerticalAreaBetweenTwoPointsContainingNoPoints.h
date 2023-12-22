class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int max_width = 0; 
        set<int> x_values;

        for(vector<int>& point : points) {
            x_values.insert(point[0]);
        }
        for(auto it = next(x_values.begin()); it != x_values.end(); it++) {
            max_width = max(max_width, *it - *prev(it) );
        }

        return max_width;
    }
};
//https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/