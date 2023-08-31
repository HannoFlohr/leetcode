class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp (n+1, n+2);
        dp[0] = 0;

        //loop through all ranges
        for(int i = 0; i <= n; ++i)
            //loop through each valid position with the current range 
            for(int j = max(i-ranges[i]+1, 0); j <= min(i+ranges[i], n); ++j)
                //min of not taking current range or taking it for each position
                dp[j] = min(dp[j], dp[max(0, i-ranges[i])]+1);

        return dp[n] < n+2 ? dp[n] : -1;
    }
};
//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/