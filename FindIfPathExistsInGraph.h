class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> neighbors (n);
        for(auto &e : edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }

        vector<bool> visited (n, false);
        queue<int> q;
        q.push(source);
        int cur;

        while(!q.empty()) {
            cur = q.front();
            q.pop();
            visited[cur] = true;

            if(cur == destination)
                return true;

            for(auto &neighbor : neighbors[cur])
                if(!visited[neighbor])
                    q.push(neighbor);
        }

        return false;
    }
};
//https://leetcode.com/problems/find-if-path-exists-in-graph/