class Solution {
private: 
    int seats;
    long long result;

    int dfs(const vector<vector<int>>& graph, int node, int previous, int people=1) {
        for(const auto& neighbor : graph[node]) {
            if(neighbor == previous) continue;
            people += dfs(graph, neighbor, node);
        }

        if(node != 0) 
            result += (people + seats - 1) / seats;
        return people;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        result = 0L;

        vector<vector<int>> graph (roads.size()+1); 
        for(const auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        
        dfs(graph, 0, 0);

        return result;
    }
};
//https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/