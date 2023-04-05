class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int result = INT_MAX;
        vector<vector<pair<int,int>>> adjacent (n+1);
        for(auto& edge : roads) {
            adjacent[edge[0]].push_back({edge[1], edge[2]});
            adjacent[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited (n+1, false);
        queue<int> q;
        int cur;
        q.push(1);
        visited[1] = true;

        while(!q.empty()) {
            cur = q.front();
            q.pop();

            for(auto& [node, distance] : adjacent[cur]) {
                result = min(result, distance);
                if(!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/