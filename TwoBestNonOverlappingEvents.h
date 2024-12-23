class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int n = events.size(), best_of_two = 0, max_value = 0;
        map<int,int> best_value_at_time;

        while(n--) {
            auto it = best_value_at_time.upper_bound(events[n][1]);
            max_value = max(max_value, events[n][2]);
            best_value_at_time[events[n][0]] = max_value;

            if(it == best_value_at_time.end())
                best_of_two = max(best_of_two, max_value);
            else
                best_of_two = max(best_of_two, events[n][2] + it->second);
        }

        return best_of_two;
    }
};
//https://leetcode.com/problems/two-best-non-overlapping-events/