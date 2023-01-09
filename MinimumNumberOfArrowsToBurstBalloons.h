class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);

        int arrows = 0, position = 0;
        for(auto &point : points)
            if(arrows == 0 || point[0] > position) {
                position = point[1];
                arrows++;
            }

        return arrows;
    }
};
//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/