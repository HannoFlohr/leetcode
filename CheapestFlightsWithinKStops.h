class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int MAX_COST = 1e8; //1e8 > (max flights length * max price of a flight)
        vector<int> costToGetTo (n, MAX_COST);  
        costToGetTo[src] = 0;

        while(k-- >= 0) {
            vector<int> cost (costToGetTo);

            for(const auto& flight : flights) 
                cost[flight[1]] = min(cost[flight[1]], costToGetTo[flight[0]] + flight[2]);
 
            costToGetTo = cost;
        }
    
        return costToGetTo[dst] == MAX_COST ? - 1 : costToGetTo[dst];
    }
};
//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm 