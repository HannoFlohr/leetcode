class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int n = heights.size(), queriessize = queries.size();
        vector<vector<vector<int>>> sorted_queries (n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> result (queriessize, -1);

        //check if a result can be deduced directly
        for(int qi = 0; qi < queriessize; ++qi) {
            int i = queries[qi][0], j = queries[qi][1];
            if(i < j && heights[i] < heights[j])
                result[qi] = j;
            else if(i > j && heights[i] > heights[j])
                result[qi] = i;
            else if(i == j)
                result[qi] = i;
            //if no direct result: arrange query by max index
            else
                sorted_queries[max(i,j)].push_back({max(heights[i], heights[j]), qi});
        }

        for(int i = 0; i < n; ++i) {
            while(!q.empty() && q.top()[0] < heights[i]) {
                result[q.top()[1]] = i;
                q.pop();
            }
            for(auto& query : sorted_queries[i])
                q.push(query);
        }

        return result;
    }
};
//https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/