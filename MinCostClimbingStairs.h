class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost_a = cost[0], cost_b = cost[1], cost_c;

        for(size_t i=2; i<cost.size(); i++) {
            cost_c = cost[i] + min(cost_a, cost_b);
            cost_a = cost_b;
            cost_b = cost_c;
        }

        return min(cost_a, cost_b);
    }
};
//https://leetcode.com/problems/min-cost-climbing-stairs/