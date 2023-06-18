class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        const int cutsSize = cuts.size();
        vector<vector<int>> dp (cutsSize, vector<int>(cutsSize)); //dp[i][j] min cost to cut between cuts[i] and cuts[j]

        for(int d = 2; d < cutsSize; ++d) {
            for(int i = 0; i < cutsSize-d; ++i) {
                dp[i][i+d] = INT_MAX;
                for(int m = i+1; m < i+d; ++m)
                    dp[i][i+d] = min(dp[i][i+d], dp[i][m] + dp[m][i+d] + cuts[i+d] - cuts[i]);
            }
        }

        return dp[0][cutsSize-1];
    }
};
//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/