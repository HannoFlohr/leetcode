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

    void Union(vector<int>& num, int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) {
            return;
        }
        if(num[a] < num[b]) {
            swap(a,b);
        }
        v[b] = a;
        num[a] += num[b];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1) {
            return true;
        }

        UnionFind uf (n);
        vector<int> num (n, 1);
        unordered_map<int,int> found_divisor_at;

        for(int i = 0; i < n; ++i) {
            int cur = nums[i];
            if(cur == 1) {
                return false;
            }

            for(int divisor = 2; divisor*divisor <= cur; ++divisor) {
                if(cur % divisor != 0) {
                    continue;
                }

                if(found_divisor_at.count(divisor) > 0) {
                    uf.Union(num, i, found_divisor_at[divisor]);
                }
                else {
                    found_divisor_at[divisor] = i;
                }
                while(cur % divisor == 0) {
                    cur /= divisor;
                }
            }

            if(cur > 1) {
                if(found_divisor_at.count(cur) > 0) 
                    uf.Union(num, i, found_divisor_at[cur]);
                else
                    found_divisor_at[cur] = i;
            }
        }

        return num[uf.find(0)] == n;
    }
};
//https://leetcode.com/problems/greatest-common-divisor-traversal/

/*
use disjointset to construct a undirected graph; each element of input array 'nums' is a node
- for each array element 'cur': find all prime factors 
- and put 'cur' in the sets of its prime factors
*/