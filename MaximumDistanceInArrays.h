class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        int min1i = -1, min2i = -1, max1i = -1, max2i = -1;

        for(int i = 0; i < arrays.size(); ++i) {
            if(arrays[i][0] < min1) {
                min2 = min1;
                min2i = min1i;
                min1 = arrays[i][0];
                min1i = i;
            }
            else if(arrays[i][0] < min2) {
                min2 = arrays[i][0];
                min2i = i;
            }

            if(arrays[i].back() > max1) {
                max2 = max1;
                max2i = max1i;
                max1 = arrays[i].back();
                max1i = i;
            }
            else if(arrays[i].back() > max2) {
                max2 = arrays[i].back();
                max2i = i;
            }
        }

        int max_distance = 0; 
        if(min1i != max1i) {
            max_distance = max(max_distance, max1 - min1);
        }
        else {
            max_distance = max(max_distance, max1 - min2);
            max_distance = max(max_distance, max2 - min1);
        }

        return max_distance;
    }
};
//https://leetcode.com/problems/maximum-distance-in-arrays/