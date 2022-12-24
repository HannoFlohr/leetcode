class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cur;
        unordered_set<int> keys = {0};
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            cur = q.front(); 
            q.pop();

            for(auto &i : rooms[cur])
                if(keys.find(i) == keys.end()) {
                    keys.insert(i);
                    q.push(i);

                    if(keys.size() == n)
                        return true;
                }
        }
        
        return keys.size() == n;
    }
};
//https://leetcode.com/problems/keys-and-rooms/