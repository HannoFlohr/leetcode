class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        //sort items by price
        sort(items.begin(), items.end());

        //fill a priority queue with the queries and their corresponding index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 0; i < queries.size(); ++i)
            q.push({queries[i], i});

        int max_beauty = 0, cur_item = 0;
        while(!q.empty()) {
            auto [query, index] = q.top();
            q.pop();
            //update max beauty up to current query
            while(cur_item < items.size() && items[cur_item][0] <= query) {
                max_beauty = max(max_beauty, items[cur_item][1]);
                ++cur_item;
            }
            //set max beauty for current query
            queries[index] = max_beauty;
        }

        return queries;
    }
};
//https://leetcode.com/problems/most-beautiful-item-for-each-query/