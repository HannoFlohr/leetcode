class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adjacent (n, vector<int>());
        vector<int> indegree (n, 0), min_height_roots;
        for(auto &edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        int qsize, node;
        //add all leaf nodes to queue
        for(int i=0; i<n; i++)
            if(indegree[i] == 1) {
                q.push(i);
                indegree[i]--;
            }

        while(!q.empty()) {
            qsize = q.size();
            min_height_roots.clear();

            for(int _=0; _<qsize; _++) {
                node = q.front();
                q.pop();
                min_height_roots.push_back(node);

                for(auto &child : adjacent[node]) {
                    indegree[child]--;
                    if(indegree[child] == 1)
                        q.push(child);
                }
            }
        }


        return min_height_roots;
    }
};
//https://leetcode.com/problems/minimum-height-trees/