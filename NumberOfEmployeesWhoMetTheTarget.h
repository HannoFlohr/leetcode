class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(int h : hours) {
            if(h >= target) {
                ++count;
            }
        }
        return count;
    }
};
//https://leetcode.com/problems/number-of-employees-who-met-the-target/