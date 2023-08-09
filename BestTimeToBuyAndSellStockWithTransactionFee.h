class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int no_stock = 0, one_stock = INT_MIN, tmp;

        for(const int& price : prices) {
            tmp = no_stock;
            no_stock = max(no_stock, one_stock+price); //update by selling current stock
            one_stock = max(one_stock, tmp-price-fee); //update by buying current stock
        }

        return no_stock;
    }
};
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/