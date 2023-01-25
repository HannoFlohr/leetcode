class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int days = prices.size();
        int min_buy;
        vector<vector<int>> dp (3, vector<int>(days, 0)); //max profit of 0,1,2 transactions on i-th day
        
        for(int transactions=1; transactions<=2; transactions++) {
            min_buy = prices[0];
            
            for(int i=1; i<days; i++) {
                min_buy = min(min_buy, prices[i] - dp[transactions-1][i-1]); 
                dp[transactions][i] = max(dp[transactions][i-1], prices[i] - min_buy); 
            }
        }

        return dp[2][days-1];
    }
};
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX, sell1 = 0, sell2 = 0;

        for(auto &price : prices) {
            buy1 = min(buy1, price);
            sell1 = max(sell1, price - buy1);
            buy2 = min(buy2, price - sell1);
            sell2 = max(sell2, price - buy2);
        }

        return sell2;
    }
};

/*
we start with 0 budget
profit for first transaction sell1 = price[i] - buy1  -> minimize buy1 for max profit
for the second transaction we can thus spend price[i] - sell1 (=buy2), because sell1 was already earned 
profit for the second transaction sell2 = price[i] - buy2 -> minimize buy2 for max profit
(each for some i=0,..prices.size())
*/