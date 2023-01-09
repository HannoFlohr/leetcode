class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int max_points_on_line = 0, max_local, same_point, vertical, a, b, gcd;

        for(int i = 0; i < n; i++) {
            map<pair<int,int>, int> count;
            max_local = 0, same_point = 0, vertical = 0; 

            for(int j = i+1; j < n; j++) {
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    same_point++;
                    continue;
                }
                else if(points[j][0] == points[i][0])
                    vertical++;
                else {
                    a = points[j][0] - points[i][0];
                    b = points[j][1] - points[i][1];
                    gcd = __gcd(a,b);
                    a /= gcd;
                    b /= gcd;

                    count[{a,b}]++;
                    max_local = max(max_local, count[{a,b}]); 
                }

                max_local = max(max_local, vertical);
            }

            max_points_on_line = max(max_points_on_line, max_local + same_point + 1);
        }

        return max_points_on_line;
    }
};
//https://leetcode.com/problems/max-points-on-a-line/