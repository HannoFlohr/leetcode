class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallest_distance = INT_MAX, smallest_index = -1;

        for(int i = 0; i < points.size(); ++i) {
            if(points[i][0] != x && points[i][1] != y) {
                continue;
            }

            int manhattan_distance = abs(points[i][0] - x) + abs(points[i][1] - y);
            if(manhattan_distance < smallest_distance) {
                smallest_distance = manhattan_distance;
                smallest_index = i;
            }
        }

        return smallest_index;
    }
};
//https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/