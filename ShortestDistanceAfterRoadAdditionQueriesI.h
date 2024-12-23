class Solution {
private:
    int dijkstra(const vector<vector<pair<int,int>>>& graph, int n) {
        vector<int> distances (n, INT_MAX);
        distances[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, 0});

        while(!q.empty()) {
            auto [distance, city] = q.top();
            q.pop();
            
            if(city == n-1)
                return distances[city];
            if(distance > distances[city])
                continue;

            for(pair<int,int> next : graph[city]) {
                int next_distance = distance + next.second;
                if(next_distance < distances[next.first]) {
                    distances[next.first] = next_distance;
                    q.push({next_distance, next.first});
                }
            }
        }

        return distances[n-1];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> graph (n);
        for(int i = 0; i < n-1; ++i)
            graph[i].push_back({i+1, 1});

        vector<int> results;
        for(vector<int>& query : queries) {
            graph[query[0]].push_back({query[1], 1});
            results.push_back(dijkstra(graph, n));
        }

        return results;
    }
};
//https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/