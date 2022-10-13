class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double largestArea = 0.0;
        
        for(auto &i : points)
            for(auto &j : points)
                for(auto &k : points)
                    largestArea = max(largestArea, 0.5 * abs( i[0]*j[1] - i[0]*k[1] + j[0]*k[1] - j[0]*i[1] + k[0]*i[1] - k[0]*j[1] ) );
        
        return largestArea;
    }
};
//https://leetcode.com/problems/largest-triangle-area/

//formula: https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/