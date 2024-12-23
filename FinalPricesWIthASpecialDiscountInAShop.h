class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        for(int i = 0; i < n-1; ++i) {
            int j = i+1;
            while(j < n && prices[j] > prices[i])
                ++j;
            if(j == n)
                continue;
            prices[i] -= prices[j];
        }
        return prices;
    }
};
//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/