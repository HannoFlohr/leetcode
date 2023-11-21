struct State {
    int mask, node, distance;
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        unordered_set<int> visited;
        int all_visited = (1<<n)-1;
        queue<State> q;

        for(int i = 0; i < n; ++i) {
            q.push({1<<i, i, 0});
            visited.insert((1<<i)*16+i);
        }      

        while(!q.empty()) {
            State cur = q.front();
            q.pop();

            if(cur.mask == all_visited) {
                return cur.distance;
            }

            for(int neighbor : graph[cur.node]) {
                int mask = cur.mask | (1<<neighbor);
                int hash = mask*16+neighbor;

                if(visited.find(hash) == visited.end()) {
                    visited.insert(hash);
                    q.push({mask, neighbor, cur.distance+1});
                }
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/shortest-path-visiting-all-nodes/