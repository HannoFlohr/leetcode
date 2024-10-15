class Solution {
private:
//check for cycle
    bool dfs_cycle(vector<vector<int>>& graph, int i, vector<int>& color) {
        color[i] = 1;
        for(int j : graph[i]) {
            if(color[j] == 0) {
                if(dfs_cycle(graph, j, color)) {
                    return true;
                }
            }
            else if(color[j] == 1) {
                return true;
            }
        }
        color[i] = 2;
        return false;
    }
    bool find_cycle(vector<vector<int>>& graph, int n) {
        vector<int> color (n,0);
        for(int i = 0; i < n; ++i) {
            if(color[i] == 0 && dfs_cycle(graph, i, color)) {
                return true;
            }
        }
        return false;
    }

//topological sort
    void dfs_topo(vector<vector<int>>& graph, int i, vector<int>& res, vector<bool>& visited) {
        visited[i] = true;
        for(int j : graph[i]) {
            if(!visited[j]) {
                dfs_topo(graph, j, res, visited);
            }
        }
        res.push_back(i);
    }
    void topological_sort(vector<vector<int>>& graph, int n, vector<int>& res) {
        vector<bool> visited (n, false);
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs_topo(graph, i, res, visited);
            }
        }
        reverse(res.begin(), res.end());
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> graph1 (k), graph2 (k);

        for(vector<int>& condition : rowConditions) {
            graph1[condition[0]-1].push_back(condition[1]-1);
        }     
        for(vector<int>& condition : colConditions) {
            graph2[condition[0]-1].push_back(condition[1]-1);
        }

        //check for cycle in any of the two graphs
        if(find_cycle(graph1, k) || find_cycle(graph2, k)) {
            return vector<vector<int>>();
        }

        //sort both graphs
        vector<int> res1, res2;
        topological_sort(graph1, k, res1);
        topological_sort(graph2, k, res2);

        //create matrix
        vector<vector<int>> matrix (k, vector<int>(k,0));
        map<int,int> m;
        for(int i = 0; i < k; ++i) {
            m[res2[i]] = i;
        }
        for(int i = 0; i < k; ++i) {
            matrix[i][m[res1[i]]] = res1[i]+1;
        }

        return matrix;
    }
};
//https://leetcode.com/problems/build-a-matrix-with-conditions/