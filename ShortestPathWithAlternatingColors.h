class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adjacent (n);
        for(const auto& edge : redEdges)
            adjacent[edge[0]].emplace_back(edge[1], 0);
        for(const auto& edge : blueEdges)
            adjacent[edge[0]].emplace_back(edge[1], 1);

        vector<int> distances (n, -1);
        queue<vector<int>> q;
        q.push(vector<int>{0,0,-1});

        while(!q.empty()) {
            auto current = q.front();
            q.pop();

            if(distances[current[0]] == -1)
                distances[current[0]] = current[1];

            for(auto& a : adjacent[current[0]]) {
                if(current[2] != a.second && a.first != -1) {
                    q.push(vector<int>{a.first, current[1]+1, a.second});
                    a.first = -1;
                }
            }  
        }
        
        return distances;
    }
};
//https://leetcode.com/problems/shortest-path-with-alternating-colors/