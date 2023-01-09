class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int n = intervals.size();
        const vector<int> q_in = queries;
        priority_queue<vector<int>> pq;
        unordered_map<int,int> min_intervals;
        int i = 0, left, right;

        sort(intervals.begin(), intervals.end());
        sort(queries.begin(), queries.end());

        for(int &query : queries) {
            while(i < n && intervals[i][0] <= query) {
                left = intervals[i][0], right = intervals[i++][1];
                pq.push({left-right-1, right});
            }
            while(!pq.empty() && pq.top()[1] < query) 
                pq.pop();

            min_intervals[query] = pq.empty() ? -1 : -pq.top()[0];
        } 

        vector<int> result (q_in.size());
        for(int i=0; i<q_in.size(); i++)
            result[i] = min_intervals[q_in[i]];

        return result;
    }
};
//https://leetcode.com/problems/minimum-interval-to-include-each-query/