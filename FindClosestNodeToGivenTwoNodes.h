class Solution {
private:
    void dfs(int node, vector<int>& distances, const vector<int>& edges) {
        int distance = 0;
        while(node != -1 && distances[node] == INT_MAX) {
            distances[node] = distance++;
            node = edges[node];
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n = edges.size();

        vector<int> distance1 (n, INT_MAX), distance2 (n, INT_MAX);
        dfs(node1, distance1, edges);
        dfs(node2, distance2, edges);

        int min_distance = INT_MAX, result_node = -1;
        for(size_t i=0; i<n; i++) {
            if(distance1[i] == INT_MAX || distance2[i] == INT_MAX) 
                continue;
            if(min_distance > max(distance1[i], distance2[i])) {
                min_distance = max(distance1[i], distance2[i]);
                result_node = i;
            }
        }

        return result_node;
    }
};
//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

/* first approach using a bfs 
class Solution {
private:
    void bfs(int start, vector<int>& distance, const vector<int>& edges) {
        queue<int> q;
        int cur;
        q.push(start);
        distance[start] = 0;
        
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(edges[cur] != -1 && distance[edges[cur]] == INT_MAX) {
                q.push(edges[cur]);
                distance[edges[cur]] = distance[cur] + 1;
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n = edges.size();

        vector<int> distance1 (n, INT_MAX), distance2 (n, INT_MAX);
        bfs(node1, distance1, edges);
        bfs(node2, distance2, edges);

        int min_distance = INT_MAX, result_node = -1;
        for(size_t i=0; i<n; i++) {
            if(distance1[i] == INT_MAX || distance2[i] == INT_MAX) 
                continue;
            if(min_distance > max(distance1[i], distance2[i])) {
                min_distance = max(distance1[i], distance2[i]);
                result_node = i;
            }
        }

        return result_node;
    }
};
*/ 