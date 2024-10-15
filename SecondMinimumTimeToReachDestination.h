class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //set up adjacencies in the graph
        vector<vector<int>> graph (n);
        for(vector<int>& edge : edges) {
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }    

        //bfs starting at the goal
        vector<int> distance (n, 1e9);
        distance[n-1] = 0;
        queue<int> q;
        q.push(n-1);
        int cur;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            for(int neighbor : graph[cur]) {
                if(distance[neighbor] == 1e9) {
                    distance[neighbor] = distance[cur] + 1;
                    q.push(neighbor);
                }
            }
        }

        //check for path with needed length 
        int path_length = distance[0]+2;
        q.push(0);
        bool found = false;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            for(int neighbor : graph[cur]) {
                if(distance[neighbor] == distance[cur]) {
                    path_length--;
                    found = true;
                    break;
                }
                else if(distance[neighbor] == distance[cur]-1) {
                    q.push(neighbor);
                }
            }
            if(found) {
                break;
            }
        }

        //calculate needed time
        int time_needed = 0;
        for(int i = 0; i < path_length; ++i) {
            if((time_needed / change) % 2 == 1) {
                time_needed = ((time_needed / change) + 1) * change;
            }
            time_needed += time;
        }

        return time_needed;
    }
};
//https://leetcode.com/problems/second-minimum-time-to-reach-destination/