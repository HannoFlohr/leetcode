class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if(n <= 1) return 0;
        
        if(k >= n/2) {
            int max_profit = 0;
            for(int i=1; i<n; i++) {
                if(prices[i] > prices[i-1])
                    max_profit += prices[i] - prices[i-1];
            }
            return max_profit;
        }
        
        vector<vector<int>> max_profit (k+1, vector<int>(n,0));
        for(int i=1; i<=k; i++) {
            int cur_max = max_profit[i-1][0] - prices[0];
            for(int j=1; j<n; j++) {
                max_profit[i][j] = max(max_profit[i][j-1], prices[j]+cur_max);
                cur_max = max(cur_max, max_profit[i-1][j]-prices[j]);
            }
        }
        return max_profit[k][n-1];
    }
};
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/