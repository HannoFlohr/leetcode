class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];} );
        
        int result = -1;
        vector<int> last;
        last = intervals[0];
        
        for(auto &i : intervals) {
            if(last[1] > i[0])
                result++;
            else
                last = i;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/non-overlapping-intervals/