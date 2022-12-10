class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minimum_area = INT_MAX;
        vector<int> intersection;

        //map possible y values to x values
        unordered_map<int, set<int>> y_at_x;
        for(auto &p : points) y_at_x[p[0]].insert(p[1]);

        for(auto i = begin(y_at_x); i != end(y_at_x); i++) {
            for(auto j = next(i); j != end(y_at_x); j++) {
                //skip x's with less than 2 y's (no parallel to axes)
                if(i->second.size() < 2 || j->second.size() < 2) continue;

                intersection.clear();
                //get intersection of the y values at i and j
                set_intersection(begin(i->second), end(i->second), begin(j->second), end(j->second), back_inserter(intersection));

                //compare area formed by intersection values against the minimum area
                for(int k = 1; k < intersection.size(); k++) 
                    minimum_area = min(minimum_area, abs(j->first - i->first) * (intersection[k] - intersection[k-1]));
            }
        }

        return minimum_area == INT_MAX ? 0 : minimum_area;
    }
};
//https://leetcode.com/problems/minimum-area-rectangle/