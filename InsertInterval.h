class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        //increment while not overlapping before newInterval
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            i++;
        }
        
        //overlap -> merge
        int insert = i;
        while(i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        //delete the overlapping interval(s) from insert to current i
        intervals.erase(intervals.begin()+insert, intervals.begin()+i);
        //insert new interval
        intervals.insert(intervals.begin()+insert, newInterval);
        
        return intervals;
    }
};
//https://leetcode.com/problems/insert-interval/