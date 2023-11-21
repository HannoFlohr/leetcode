class Graph {
private:
    vector<vector<int>> adjacent;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adjacent = vector<vector<int>>(n, vector<int>(n, 1e9));

        for(const auto& edge : edges)
            adjacent[edge[0]][edge[1]] = edge[2];

        for(int i = 0; i < n; i++)
            adjacent[i][i] = 0;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    adjacent[j][k] = min(adjacent[j][k], adjacent[j][i] + adjacent[i][k]);
    }
    
    void addEdge(vector<int> edge) {
        for(int i = 0; i < adjacent.size(); i++)
            for(int j = 0; j < adjacent.size(); j++)
                adjacent[i][j] = min(adjacent[i][j], adjacent[i][edge[0]] + adjacent[edge[1]][j] + edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        if(adjacent[node1][node2] == 1e9)
            return -1;
        return adjacent[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
 
 //https://leetcode.com/problems/design-graph-with-shortest-path-calculator/