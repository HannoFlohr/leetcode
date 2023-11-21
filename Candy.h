class Solution {
public:
    int candy(vector<int>& ratings) {
        const int children = ratings.size();
        int i = 1, candies = children;

        while(i < children) {
            if(ratings[i] == ratings[i-1]) {
              ++i;
              continue;
            }

            //(consecutive) increasing
            int peak = 0;
            while(ratings[i] > ratings[i-1]) {
              ++peak;
              candies += peak;
              ++i;
              if(i == children)
                return candies;
            }

            //(consecutive) decreasing
            int valley = 0;
            while(i < children && ratings[i] < ratings[i-1]) {
              ++valley;
              candies += valley;
              ++i;
            }

            //keep only higher of the two peaks
            candies -= min(peak, valley);
        }

        return candies;
    }
};
//https://leetcode.com/problems/candy/