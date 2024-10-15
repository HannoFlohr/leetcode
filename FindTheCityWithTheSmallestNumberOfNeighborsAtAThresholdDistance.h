class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int city = 0, smallest = n;
        vector<vector<int>> distance (n, vector<int>(n, 1e4+1));
        //initialize distances using data for edges
        for(vector<int>& edge : edges) {
            distance[edge[0]][edge[1]] = distance[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }
        //update distances for from all cities to all others
        for(int check = 0; check < n; ++check) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][check]+distance[check][j]);
                }
            }
        }
        //loop through all cities; count cities within threshold distance to the current one
        //update if count is smaller
        for(int i = 0; i < n; ++i) {
            int count = 0;
            for(int j = 0; j < n; ++j) {
                if(distance[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if(count <= smallest) {
                smallest = count;
                city = i;
            }
        }
        return city;
    }
};
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/