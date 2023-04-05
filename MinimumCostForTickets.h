class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> dayset (days.begin(), days.end());
        vector<int> dp (366);

        for(int day=1; day<=365; day++) {
            if(dayset.find(day) == dayset.end()) 
                dp[day] = dp[day-1]; 
            else
                dp[day] = min({dp[day-1]+costs[0], dp[max(0, day-7)]+costs[1], dp[max(0, day-30)]+costs[2]});
        }
    
        return dp[365];
    }
};
//https://leetcode.com/problems/minimum-cost-for-tickets/