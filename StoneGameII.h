class Solution {
private:
    int solve(const vector<int>& piles, vector<vector<int>>& dp, const vector<int>& suffixSum, int i, int M) {
        //edge cases
        if(i == piles.size())
            return 0;
        if(i+2*M >= piles.size())
            return suffixSum[i];
        //already visited
        if(dp[i][M] != 0)
            return dp[i][M];

        //look for best result if 1..2*M piles are taken
        int result = 0;
        for(int take = 1; take <= 2*M; ++take)
            result = max(result, suffixSum[i] - solve(piles, dp, suffixSum, i+take, max(M, take)));

        dp[i][M] = result;
        return result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> dp (n, vector<int>(n, 0));
        vector<int> suffixSum (n);
        suffixSum[n-1] = piles[n-1];

        for(int i = n-2; i >= 0; --i)
            suffixSum[i] = piles[i] + suffixSum[i+1];

        return solve(piles, dp, suffixSum, 0, 1);
    }
};
//https://leetcode.com/problems/stone-game-ii/