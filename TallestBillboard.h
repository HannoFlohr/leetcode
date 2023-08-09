class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp (sum+1, -1), dp_save (sum+1);
        dp[0] = 0;

        for(const int& rod : rods) {
            dp_save = dp;

            for(int i = 0; i <= sum-rod; ++i) {
                if(dp_save[i] < 0)
                    continue;

                dp[i+rod] = max(dp[i+rod], dp_save[i]);
                dp[abs(i-rod)] = max(dp[abs(i-rod)], dp_save[i] + min(i, rod));
            }
        }

        return dp[0];
    }
};
//https://leetcode.com/problems/tallest-billboard/