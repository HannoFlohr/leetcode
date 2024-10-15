class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> times;
        for(vector<int>& interval : intervals) {
            //start using a room for interval i
            times.push_back({interval[0], 1});
            //end using a room for interval i
            times.push_back({interval[1]+1, -1});
        }
        //sort the start and end times
        sort(times.begin(), times.end());

        //check how many rooms are needed for all times
        int groups = 0, current_groups = 0;
        for(vector<int>& time : times) 
            groups = max(groups, current_groups += time[1]);

        return groups;
    }
};
//https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/