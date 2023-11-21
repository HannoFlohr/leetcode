class Solution {
private:
    int distance(int x1, int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y1-y2);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int pointssize = points.size();
        int min_cost = 0;
        vector<int> min_distances(pointssize, 0);
        min_distances[0] = INT_MAX;

        for(int i = 1; i < pointssize; ++i) {
            min_distances[i] = distance(points[0][0],points[0][1],points[i][0],points[i][1]);
        }

        for(int i = 1; i < pointssize; ++i) {
            auto it = min_element(min_distances.begin(), min_distances.end());
            min_cost += *it;

            int index = it - min_distances.begin();
            *it = INT_MAX;

            for(int j = 0; j < pointssize; ++j) {
                if(min_distances[j] != INT_MAX) {
                    min_distances[j] = min(min_distances[j], distance(points[j][0],points[j][1],points[index][0],points[index][1]));
                }
            } 
        }

        return min_cost;
    }
};
//https://leetcode.com/problems/min-cost-to-connect-all-points/