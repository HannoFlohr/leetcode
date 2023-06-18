class Solution {
private:
    int find(vector<int>& ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> disjointset_both (n+1, -1);
        int keep_edges = 0;

        for(int type = 3; type > 0; --type) {
            auto disjointset_one = disjointset_both;
            auto &ds = type == 3 ? disjointset_both : disjointset_one;

            for(auto& edge : edges) {
                if(edge[0] != type)
                    continue;

                int i = find(ds, edge[1]), j = find(ds, edge[2]);
                if(i == j) 
                    continue;

                ++keep_edges;
                if(ds[j] < ds[i])
                    swap(i,j);
                ds[i] += ds[j];
                ds[j] = i;
            }

            if(type != 3 && ds[find(ds, 1)] != -n)
                return -1;
        }

        return edges.size() - keep_edges;
    }
};
//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/