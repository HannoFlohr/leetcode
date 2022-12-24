class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result;
        //compute distances and set triplets {i,x,distance}
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                result.push_back({i, j, abs(i-rCenter) + abs(j-cCenter)});

        //sort by distance
        sort(begin(result), end(result), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[2] < v2[2];
        });
        //pop distance
        for(auto &v : result)
            v.pop_back();
        return result;
    }
};
//https://leetcode.com/problems/matrix-cells-in-distance-order/