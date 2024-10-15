class Solution {
private:
    void dfs(vector<vector<int>>& neighbors, int i, int j, vector<vector<int>>& answer) {
        for(int neighbor : neighbors[j]) {
            if(answer[neighbor].empty() || answer[neighbor].back() != i) {
                answer[neighbor].push_back(i);
                dfs(neighbors, i, neighbor, answer);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n), neighbors(n);

        for(vector<int>& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; ++i) {
            dfs(neighbors, i, i, answer);
        }

        return answer;
    }
};
//https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/