class Solution {
private:
    vector<int> topologicalSort(vector<unordered_set<int>>& graph, vector<int>& indegree) {
        vector<int> sorted;
        int checked = 0, n = graph.size();
        
        queue<int> q;
        for(int node = 0; node < n; ++node)
            if(indegree[node] == 0)
                q.push(node);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ++checked;
            sorted.push_back(node);

            for(int neighbor : graph[node]) {
                --indegree[neighbor];
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        return checked < n ? vector<int>{} : sorted;
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //set nodes without a group to solo groups
        for(int node = 0; node < n; ++node)
            if(group[node] == -1)
                group[node] = m++;

        vector<unordered_set<int>> group_graph (m), node_graph (n);
        vector<int> group_indegree (m), node_indegree (n); 

        //create graph for groups and nodes
        for(int node = 0; node < n; ++node) {
            int cur_group = group[node];

            for(auto before_node : beforeItems[node]) {
                int before_group = group[before_node];

                if(cur_group != before_group && !group_graph[before_group].count(cur_group)) {
                    group_graph[before_group].emplace(cur_group);
                    ++group_indegree[cur_group];
                }

                if(!node_graph[before_node].count(node)) {
                    node_graph[before_node].emplace(node);
                    ++node_indegree[node];
                }
            }
        }

        //toplogical sort at group and node level
        vector<int> sorted_groups = topologicalSort(group_graph, group_indegree);
        vector<int> sorted_node = topologicalSort(node_graph, node_indegree);

        //sort the sorted nodes for each group
        vector<vector<int>> group_sorted_nodes (m);
        for(int node : sorted_node)
            group_sorted_nodes[group[node]].push_back(node);

        //sort all nodes into one vector according to the sorted groups
        vector<int> sorted;
        for(int group : sorted_groups)
            for(int node : group_sorted_nodes[group])
                sorted.push_back(node);

        return sorted;    
    }
};
//https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/