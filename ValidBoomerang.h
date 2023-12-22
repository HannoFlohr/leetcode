class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) !=
                (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
    }
};
//https://leetcode.com/problems/valid-boomerang/

/*
three points A B C
calculate slope of AB and AC and check if AB != AC

AB = A0 - B0 / A1 - B1
AC = A0 - C0 / A1 - C1
AB != AC 
A0 - B0 / A1 - B1 != A0 - C0 / A1 - C1
(A0 - B0) * (A1 - C1) != (A0 - C0) * (A1 - B1) 
*/