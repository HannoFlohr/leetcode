class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> dp (n, INT_MIN);

        for(int cur = n-1; cur >= 0; --cur) {
            for(int take = 0, sum = 0; take < 3 && cur+take < n; ++take) {
                sum += stoneValue[cur+take];
                dp[cur] = max(dp[cur], sum - (cur+take+1 < n ? dp[cur+take+1] : 0));
            }
        }

        if(dp[0] == 0) 
            return "Tie";
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};
//https://leetcode.com/problems/stone-game-iii/