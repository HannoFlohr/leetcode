class Solution {
private:
    void reconstruct(const string& airport, map<string, multiset<string>>& from_to, vector<string>& route) {
        while(from_to[airport].size()) {
            string next_airport = *from_to[airport].begin();
            from_to[airport].erase(from_to[airport].begin());
            reconstruct(next_airport, from_to, route);
        }
        route.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> from_to;
        vector<string> route;

        for(auto& ticket : tickets) {
            from_to[ticket[0]].insert(ticket[1]);
        }

        reconstruct("JFK", from_to, route);
        reverse(route.begin(), route.end());
        return route;
    }
};
//https://leetcode.com/problems/reconstruct-itinerary/