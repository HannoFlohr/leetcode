class DisjointSet {
	vector<int> parent;
public:
	DisjointSet(int n) : parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int i) {
		if (parent[i] != i)
			parent[i] = find(parent[i]);
		return parent[i]; 
	}

	void Union(int set1, int set2) {
        int i = find(set1), j = find(set2);
        if(i != j) 
            parent[i] = parent[j];
	}
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), good_paths = n;
        vector<vector<int>> adjacent (n);
        map<int, vector<int>> same_values_at;

        for(int i=0; i<n; i++)
            same_values_at[vals[i]].push_back(i);

        //connect only nodes with value less than or equal to current node
        for(auto &e : edges) {
            if(vals[e[0]] >= vals[e[1]]) 
                adjacent[e[0]].push_back(e[1]);
            else 
                adjacent[e[1]].push_back(e[0]);
        }

        DisjointSet ds (n); //disjoint set for the graph

        for(auto &[_, same_value_nodes] : same_values_at) {
            //union the nodes in the disjoint set
            for(auto node : same_value_nodes)
                for(auto neighbor : adjacent[node])
                    ds.Union(node, neighbor);

            unordered_map<int,int> groups;
            for(auto node : same_value_nodes)
                groups[ds.find(node)]++;

            for(auto &[_, size] : groups)
                good_paths += (size * (size-1) / 2);
        }

        return good_paths;
    }
};
//https://leetcode.com/problems/number-of-good-paths/