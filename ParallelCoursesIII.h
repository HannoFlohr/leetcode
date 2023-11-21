class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree (n), duration (n);
        vector<vector<int>> graph (n);
        queue<int> q;
        int cur;

        //set up graph and indegree of each node
        for(auto& edge : relations) {
            graph[edge[0]-1].push_back(edge[1]-1);
            indegree[edge[1]-1]++;
        }

        //start queue with all nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                duration[i] = time[i];
            }
        }

        //use queue to loop through all nodes and compute the min duration
        while(!q.empty()) {
            cur = q.front();
            q.pop();

            for(int next : graph[cur]) {
                duration[next] = max(duration[next], duration[cur]+time[next]);
                if(--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return *max_element(duration.begin(), duration.end());
    }
};
//https://leetcode.com/problems/parallel-courses-iii/