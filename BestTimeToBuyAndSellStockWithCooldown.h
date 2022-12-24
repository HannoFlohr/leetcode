class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        vector<int> no (prices.size(), 0); 		//max profit at day i ending with no action 
        vector<int> buy (prices.size(), 0); 	//max profit at day i ending with buy action 
        vector<int> sell (prices.size(), 0);	//max profit at day i ending with sell action
        no[0] = 0; //no action at start -> no stock
        buy[0] = -prices[0]; //buying at start -> negative profit of first price 
        sell[0] = INT_MIN; //sell not possible at start; use as lower base case

        for(int i=1; i < prices.size(); i++) {
            no[i] = max(no[i-1], sell[i-1]); 
            buy[i] = max(buy[i-1], no[i-1] - prices[i]); 
            sell[i] = buy[i-1] + prices[i];
        }

		//max overall profit end with either a sell or a no action (buy in last step definitely reduces max profit) 
        return max(no[prices.size()-1], sell[prices.size()-1]);
    }
};
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/