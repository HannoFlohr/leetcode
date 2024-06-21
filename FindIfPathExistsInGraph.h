class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int a = find(x), b = find(y);

        if(a == b) {
            return true;
        }

        if(rank[a] > rank[b]) {
            parent[b] = a;
        }
        else if(rank[a] < rank[b]) {
            parent[a] = b;
        } 
        else {
            parent[b] = a;
            rank[a]++;
        }

        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds (n);
        for(auto edge : edges) {
            ds.Union(edge[0], edge[1]);
        }
        return ds.Union(source, destination);
    }
};
https://leetcode.com/problems/find-if-path-exists-in-graph/

/* bfs solution; gives TLE now
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> neighbors (n);
        for(auto &e : edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }

        vector<bool> visited (n, false);
        queue<int> q;
        q.push(source);
        int cur;

        while(!q.empty()) {
            cur = q.front();
            q.pop();
            visited[cur] = true;

            if(cur == destination)
                return true;

            for(auto &neighbor : neighbors[cur])
                if(!visited[neighbor])
                    q.push(neighbor);
        }

        return false;
    }
};
*/