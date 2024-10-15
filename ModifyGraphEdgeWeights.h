class Solution {
private:
    void shortestPath(vector<vector<int>>& edges, int source, int difference, int run, 
            const vector<vector<pair<int,int>>>& neighbors, vector<vector<int>>& distance) {
        int n = neighbors.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0,source});
        distance[source][run] = 0;

        while(!q.empty()) {
            auto [cur_distance, cur_node] = q.top();
            q.pop();

            if(cur_distance > distance[cur_node][run])
                continue;

            for(auto& neighbor : neighbors[cur_node]) { 
                int next_node = neighbor.first, edge = neighbor.second; 
                int weight = edges[edge][2];
                if(weight == -1)
                    weight = 1;

                if(run == 1 && edges[edge][2] == -1) {
                    int new_weight = difference + distance[next_node][0] - distance[cur_node][1];
                    if(new_weight > weight) {
                        edges[edge][2] = weight = new_weight;
                    }
                }

                if(distance[next_node][run] > distance[cur_node][run] + weight) {
                    distance[next_node][run] = distance[cur_node][run] + weight;
                    q.push({distance[next_node][run], next_node});
                }
            }
        }
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        //create a representation for the graph
        vector<vector<pair<int,int>>> neighbors (n);
        for(int i = 0; i < edges.size(); ++i) {
            neighbors[edges[i][0]].emplace_back(edges[i][1], i);
            neighbors[edges[i][1]].emplace_back(edges[i][0], i);
        }

        //initialize distance array
        vector<vector<int>> distance (n, vector<int>(2, INT_MAX));
        distance[source][0] = distance[source][1] = 0;
    
        //first run to find shortest possible path in the graph (-1 weights treated as 1)
        shortestPath(edges, source, 0, 0, neighbors, distance);

        //check if a shortest possible path with at most 'target' distance is possible
        int difference = target - distance[destination][0]; 
        if(difference < 0) 
            return {};
        
        //second run to replace -1 weight edges in order to try to create a shortest path with distance 'target'
        shortestPath(edges, source, difference, 1, neighbors, distance);

        //check if a shortest path was created succesfully
        if(distance[destination][1] < target)
            return {};

        //replace remaining -1 edges
        for(auto& edge : edges) {
            if(edge[2] == -1) {
                edge[2] = 1;
            }
        }

        return edges;
    }
};
//https://leetcode.com/problems/modify-graph-edge-weights/