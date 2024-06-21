class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for(vector<int>& account : accounts) {
            max_wealth = max(max_wealth, accumulate(account.begin(), account.end(), 0));
        }
        return max_wealth;
    }
};
//https://leetcode.com/problems/richest-customer-wealth/