class Solution {
private:
    void findPaths(const vector<vector<int>>& graph, int node, vector<int>& cur_path, vector<vector<int>>& paths) {
        cur_path.push_back(node);

        if(node == graph.size() - 1) 
            paths.push_back(cur_path);

        for(auto &next : graph[node])
            findPaths(graph, next, cur_path, paths);

        cur_path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> cur_path;
        findPaths(graph, 0, cur_path, paths);
        return paths;
    }
};
//https://leetcode.com/problems/all-paths-from-source-to-target/