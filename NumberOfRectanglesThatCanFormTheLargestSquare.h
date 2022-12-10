class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> max_length_count;
        for(auto &r : rectangles)
            max_length_count[ min(r[0], r[1]) ]++;

        return (max_length_count.rbegin())->second;
    }
};
//https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/