class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        //no ops -> all values in matrix stay zero
        if(ops.size() == 0) {
            return m * n;
        }
        //all rows and columns are always incremented from the first one
        //therefore all cells with highest value are in the range
        //[0...min_x][0...min_y]
        int min_x = INT_MAX, min_y = INT_MAX;
        for(vector<int>& op : ops) {
            min_x = min(min_x, op[0]);
            min_y = min(min_y, op[1]);
        }
        //product of the min values gives the result
        return min_x * min_y;
    }
};
https://leetcode.com/problems/range-addition-ii/