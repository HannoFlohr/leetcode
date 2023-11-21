class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> filled (102);
        filled[0] = (double)poured;

        for(int row = 1; row <= query_row; ++row) {
            for(int glass = row; glass >= 0; --glass) {
                filled[glass] = max(0.0, (filled[glass]-1)/2);
                filled[glass+1] += filled[glass];
            }
        }

        return min(filled[query_glass], 1.0);
;    }
};
//https://leetcode.com/problems/champagne-tower/