class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(const int& n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n,0);
    }

    int find(const int& x) {
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    int Union(const int& x, const int& y) {
        int set1 = find(x), set2 = find(y);
        
        if(set1 != set2) {
            if(rank[set1] < rank[set2])
                parent[set1] = set2;
            else
                parent[set2] = set1;
            return true; 
        }

        return false;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet ds (n);

        for(size_t i=0; i<queries.size(); ++i)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [](auto& l, auto& r) {return l[2] < r[2]; } );
        sort(edgeList.begin(), edgeList.end(), [](auto& l, auto& r) {return l.back() < r.back(); } );

        int i = 0;
        vector<bool> results (queries.size());
        for(auto& q : queries) {
            while(i < edgeList.size() && edgeList[i][2] < q[2])
                ds.Union(edgeList[i][0], edgeList[i++][1]);

            results[q.back()] = ds.find(q[0]) == ds.find(q[1]);
        }

        return results;
    }
};
//https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/