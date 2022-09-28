class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();
        
        unordered_map<int, vector<int>> values;
        for(int i=0; i<n; i++) values[arr[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        int cur, jumps = 0;
        vector<bool> visited (n, false);
        visited[0] = true;
        
        while(!q.empty()) {
            for(int i=q.size(); i>0; i--) {
                cur = q.front();
                q.pop();
                if(cur == n-1) return jumps;

                vector<int>& jumpTo = values[arr[cur]];
                jumpTo.push_back(cur-1);
                jumpTo.push_back(cur+1);

                for(auto j:jumpTo) {
                    if(j>=0 && j<n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                jumpTo.clear();
            }
            
            jumps++;
        }
        
        return 0;
    }
};
//https://leetcode.com/problems/jump-game-iv/