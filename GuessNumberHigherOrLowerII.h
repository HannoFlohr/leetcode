class Solution {
public:
    int getMoneyAmount(int n) {
        //rows: beginning of range; columns: end of range
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0)); 
        int choose, end;
        
        for(int length = 2; length <= n; length++) {
            for(int start = 0; start <= n-length; start++) {
                end = start + length;
                
                for(int i = start; i < end; i++) {
                    choose = i+1;
                    if(i == start)
                        dp[start][end] = choose + dp[start+1][end];
                    else
                        dp[start][end] = min(dp[start][end], max(dp[start][i], dp[i+1][end]) + choose);
                }
            }
        }
        
        return dp[0][n];
    }
};
//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

/*
target is in [1,n] 
guessing x incorrectly, we know the right on is either in [1,x) or in (x,n] 
therefore cost for [1,n] equals cost for guaranteeing a win between [1,x) or (x,n] + cost of guessing x 
*/