class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //map nodes to adjacent nodes
        unordered_map<int,vector<int>> graph;
        for(vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        //set all restricted nodes to true in visited for the bfs
        vector<bool> visited (n,false);
        for(int node : restricted) {
            visited[node] = true;
        }
        
        //bfs for the visitable nodes among the remaining non-restricted nodes
        int node, qsize, count = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            qsize = q.size();
            while(qsize-- > 0) {
                node = q.front(); 
                q.pop();

                visited[node] = true;
                ++count;

                for(int next : graph[node]) {
                    if(!visited[next]) {
                        q.push(next);
                    }
                }
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/reachable-nodes-with-restrictions/