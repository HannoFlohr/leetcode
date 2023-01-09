class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size() == k) return points;

        const int n = points.size();
        map<double,vector<int>> indices_of_distance;
        vector<vector<int>> result;

        for(int i=0; i<n; i++)
            indices_of_distance[sqrt((double)points[i][0] * points[i][0] + (double)points[i][1] * points[i][1])].push_back(i); 

        for(auto &id : indices_of_distance) {
            if(k <= 0) break;

            for(auto &i : id.second) {
                result.push_back(points[i]);
                k--;
                if(k <= 0) break;
            }
        }

        return result; 
    }
};
//https://leetcode.com/problems/k-closest-points-to-origin/