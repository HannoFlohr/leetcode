class UnionFind {
private:
    vector<int> v;
public:
    UnionFind(int n) : v(n) {
        iota(v.begin(), v.end(), 0);
    }
    
    int find(int a) {
        return v[a] == a ? a : (v[a] = find(v[a]));
    }

    void Union(int a, int b) {
        v[find(b)] = find(a);
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    void reset(int a) {
        v[a] = a;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {return a[2]<b[2]; });
        
        UnionFind uf (n);
        uf.Union(0, firstPerson);

        vector<int> people;
        for(int i = 0, m = meetings.size(); i < m; ) {
            people.clear();
            int time = meetings[i][2];
            for( ; i < m && meetings[i][2] == time; ++i) {
                uf.Union(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
            }

            for(int p : people) {
                if(!uf.connected(0,p))
                    uf.reset(p);
            }
        }

        vector<int> result;
        for(int i = 0; i < n; ++i) {
            if(uf.connected(0,i)) 
                result.push_back(i);
        }

        return result;
    }
};
//https://leetcode.com/problems/find-all-people-with-secret/