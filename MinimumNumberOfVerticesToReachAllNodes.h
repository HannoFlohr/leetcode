class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //indegree of each vertex 0..n-1
        vector<int> indegree (n);
        for(const auto& edge : edges)
            indegree[edge[1]]++;

        //find all vertices with indegree 0
        vector<int> zero_indegree_vertices;
        for(int i = 0; i < n; ++i)
            if(indegree[i] == 0)
                zero_indegree_vertices.push_back(i);

        return zero_indegree_vertices;
    }
};
//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/