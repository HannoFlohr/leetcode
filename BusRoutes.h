class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> busses;
        for(int i = 0; i < routes.size(); i++) {
            for(int j : routes[i]) {
                busses[j].push_back(i);
            }
        }

        unordered_set<int> visited = {source};
        queue<pair<int,int>> q;
        q.push({source,0});

        while(!q.empty()) {
            auto [stop, bus] = q.front();
            q.pop();
            
            if(stop == target) {
                return bus;
            }

            for(int i : busses[stop]) {
                for(int j : routes[i]) {
                    if(visited.find(j) == visited.end()) {
                        visited.insert(j);
                        q.push({j, bus+1});
                    }
                }
                routes[i].clear();
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/bus-routes/