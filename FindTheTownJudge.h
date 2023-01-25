class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts (n+1, 0);
        
        for(auto &person : trust) {
            trusts[person[0]]--;
            trusts[person[1]]++;
        }

        for(int i=1; i<=n; i++)
            if(trusts[i] == n-1)
                return i;
        return -1;
    }
};
//https://leetcode.com/problems/find-the-town-judge/

/*
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts (n, 0);
        vector<int> trusted_by (n, 0);
        
        for(auto &person : trust) {
            trusts[person[0]-1]++;
            trusted_by[person[1]-1]++;
        }

        for(int i=0; i<n; i++)
            if(trusts[i] == 0 && trusted_by[i] == n-1)
                return i+1;
        return -1;
    }
};
*/