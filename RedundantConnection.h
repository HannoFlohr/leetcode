class DisjointSet {
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;  //depth of each tree
public:
	DisjointSet(int n) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find(int i) {
		if (parent[i] == i)
			return i;
		else
			return find(parent[i]);
	}

	bool Union(int set1, int set2) {
        int parent1 = find(set1), parent2 = find(set2); 
        if(parent1 == parent2)
            return false;

		if (rank[parent1] > rank[parent2]) {
			parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        }
		else {
			parent[parent1] = parent2;
			rank[parent2] += rank[parent1];
		}
		return true;
	}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds (edges.size());
        for(auto &edge : edges)
            if(!ds.Union(edge[0]-1, edge[1]-1))
                return edge;
        return {};
    }
};
//https://leetcode.com/problems/redundant-connection/