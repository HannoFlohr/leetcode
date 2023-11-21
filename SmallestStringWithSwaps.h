class DisjointSet {
private:
    vector<int> ds;
public:
    DisjointSet(int n) {
        ds = vector<int>(n, -1);
    }
    int find(int x) {
        if(ds[x] == -1) {
            return x;
        }
        return ds[x] = find(ds[x]);
    }
    void unionset(int x, int y) {
        int parent_x = find(x), parent_y = find(y);
        if(parent_x != parent_y) {
            ds[parent_y] = parent_x;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //create and union the set of nodes
        DisjointSet ds (s.length());
        for(int i = 0; i < pairs.size(); i++) {
            int x = ds.find(pairs[i][0]), y = ds.find(pairs[i][1]);
            if(x != y) {
                ds.unionset(x,y);
            }
        }

        //map groups of nodes belonging together
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < s.length(); i++) {
            groups[ds.find(i)].push_back(i);
        }
        for(auto it=groups.begin(); it!=groups.end(); it++){cout<<it->first<<" | ";for(auto i:it->second) {cout<<i<<" ";}cout<<endl;}

        //sort each group and swap their chars in the string accordingly
        for(auto group : groups) {
            string group_str = ""; 
            for(int i : group.second) {
                group_str += s[i];
            }
            sort(group_str.begin(), group_str.end());
            
            int swap = 0;
            for(int i : group.second) {
                s[i] = group_str[swap];
                swap++;
            }
        }

        return s;
    }
};
//https://leetcode.com/problems/smallest-string-with-swaps/