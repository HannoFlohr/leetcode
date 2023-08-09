class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur_altitude = 0, max_altitude = 0;

        for(const auto& g : gain) {
            cur_altitude += g;
            max_altitude = max(max_altitude, cur_altitude);
        }

        return max_altitude;
    }
};
//https://leetcode.com/problems/find-the-highest-altitude/