class Solution {
private:
    vector<int> provinces;

    int find(int x) {
        if(provinces[x] == -1)
            return x;
        return provinces[x] = find(provinces[x]);
    }

    void Union(int a, int b) {
        int parent_a = find(a), parent_b = find(b);

        if(parent_a == parent_b)
            return;

        provinces[parent_a] = parent_b;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        provinces = vector<int> (n,-1);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(isConnected[i][j])
                    Union(i,j);

        int count = 0;
        for(const auto& x : provinces)
            if(x == -1)
                count++;
        
        return count;
    }
};
//https://leetcode.com/problems/number-of-provinces/