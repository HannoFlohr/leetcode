class Solution {
private:
    const int MAXN = 1e5;
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result (2);
        vector<int> losses(MAXN+1, -1);
        
        for(auto &m : matches) {
            if(losses[m[0]]==-1) 
                losses[m[0]] = 0;
            
            if(losses[m[1]] == -1)
                losses[m[1]] = 1;
            else 
                losses[m[1]]++;
        }
        
        for(int i=1; i<=MAXN; i++) 
            if(losses[i]==0) result[0].push_back(i);
            else if(losses[i] == 1) result[1].push_back(i);
        
        return result;
    }
};
//https://leetcode.com/problems/find-players-with-zero-or-one-losses/