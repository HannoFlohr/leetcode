class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int result = 0;
        vector<vector<int>> graph (n);
        vector<int> outgoing (n);
        queue<int> q;

        //build graph
        for(vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

        }
        //fill initial queue and init outgoing vector
        for(int i = 0; i < n; ++i) {
            outgoing[i] = graph[i].size();
            if(graph[i].size() < 2)
                q.push(i);
        }
        //bfs starting at leaves
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            --outgoing[node];
            //if value of node is divisible by k: increment result
            result += values[node] % k == 0;
            
            //for all adjacent nodes: add value of current node, decrement outgoing 
            //and if the adjacent was decremented to a leaf: add to queue
            for(int next : graph[node]) {
                if(outgoing[next] == 0)
                    continue;
                values[next] += values[node] % k;
                if(--outgoing[next] == 1)
                    q.push(next);
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/maximum-number-of-k-divisible-components/