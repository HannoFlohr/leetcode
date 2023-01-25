class Solution {
private:
    int dfs(const vector<vector<int>>& adjacencyList, const vector<bool>& hasApple, int node, int depth, int previous) {
        int result = 0;

        for(auto &child : adjacencyList[node])
            if(child != previous) {
                int child_contribution = dfs(adjacencyList, hasApple, child, depth+1, node);
                if(child_contribution > 0)
                    result += child_contribution - depth; 
            }

        return result || hasApple[node] ? result+depth : 0;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjacencyList (n);
        for(auto &edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        return dfs(adjacencyList, hasApple, 0, 0, -1) * 2;
    }
};
//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/