class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) { 
        vector<int> colors (graph.size(), -1);
        queue<pair<int,int>> q; //<node,color>
        
        for(size_t i = 0; i < graph.size(); i++) {
            if(colors[i] != -1) continue;

            q.push({i,0});
            colors[i] = 0;

            while(!q.empty()) {
                auto [node,color] = q.front();
                q.pop();

                for(const auto& neighbor : graph[node]) {
                    if(colors[neighbor] == color) 
                        return false;
                    if(colors[neighbor] == -1) {
                        colors[neighbor] = !color;
                        q.push({neighbor, colors[neighbor]});
                    }
                }
            }
        }

        return true;
    }
};
//https://leetcode.com/problems/is-graph-bipartite/