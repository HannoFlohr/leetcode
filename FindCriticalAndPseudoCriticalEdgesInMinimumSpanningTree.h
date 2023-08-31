class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent = vector<int>(n);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
        rank = vector<int>(n, 1);
    }

    int Find(int x) {
        if(x == parent[x])
            return x;
        else
            return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int p_x = Find(x), p_y = Find(y);

        if(p_x == p_y)
            return;
        
        if(rank[p_x] > rank[p_y])
            swap(p_x, p_y);

        parent[p_x] = p_y;
        if(rank[p_x] == rank[p_y])
            ++rank[p_y];
    }
};

class Solution {
private:
    int getMST(int n, const vector<vector<int>>& edges, int remove_edge, int previous_edge = -1) {
        DisjointSet ds (n);

        int weight = 0;

        if(previous_edge != -1) {
            weight += edges[previous_edge][2];
            ds.Union(edges[previous_edge][0], edges[previous_edge][1]);
        }

        for(int i = 0; i < edges.size(); ++i) {
            if(i == remove_edge)
                continue;
            
            const auto& edge = edges[i];
            if(ds.Find(edge[0]) == ds.Find(edge[1]))
                continue;

            ds.Union(edge[0], edge[1]);
            weight += edge[2];
        }

        for(int i = 0; i < n; ++i)
            if(ds.Find(i) != ds.Find(0))
                return INT_MAX;

        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](const vector<int>&a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int original_mst = getMST(n, edges, -1);
        vector<int> critical, pseudo_critical;

        for(int i = 0; i < edges.size(); ++i) {
            if(original_mst < getMST(n, edges, i))
                critical.push_back(edges[i][3]);
            else if(original_mst == getMST(n, edges, -1, i))
                pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};
    }
};
//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/