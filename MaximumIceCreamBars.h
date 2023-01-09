class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        for(int i=0; i<costs.size(); i++) 
            if(coins >= costs[i]) coins -= costs[i];
            else return i;

        return costs.size();
    }
};
https://leetcode.com/problems/maximum-ice-cream-bars/

/*
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> cost_frequency;
        for(auto &cost : costs)
            cost_frequency[cost]++;

        int bars = 0;
        for(auto &cf : cost_frequency) {
            while(cf.second > 0) {
                if(coins < cf.first) return bars; 

                bars++;
                cf.second--;
                coins -= cf.first;
            }
        }

        return bars;
    }
};
*/