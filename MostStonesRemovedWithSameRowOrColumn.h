class Solution {
private: 
    unordered_map<int,int> ds;
    int single_stones = 0; //number of stones with no other stones in their row/col
    
    //union/find approach on the positions of the stones in columns/rows
    //rows in range [0,1000], columns in range [-1001,-1]
    int find(int x) {
        if(!ds.count(x)) {
            ds[x] = x;
            single_stones++;
        }
        if(x != ds[x])
            ds[x] = find(ds[x]);
        
        return ds[x];
    }
    void union_set(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) {
            ds[x] = y;
            single_stones--;
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto &s : stones) 
            union_set(s[0], ~s[1]);
        
        return stones.size() - single_stones;
    }
};
//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

//https://en.wikipedia.org/wiki/Disjoint-set_data_structure