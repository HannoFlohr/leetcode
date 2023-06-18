class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        //handle edge cases
        if(k == 0 || n >= k + maxPts) 
            return 1.0;

        vector<double> dp (n+1); //dp[i]: chance to get i points after some rounds
        dp[0] = 1.0;
        double sum = 1.0, probability = 0.0;

        for(int i = 1; i <= n; ++i) {
            dp[i] = sum / maxPts;

            if(i < k)
                sum += dp[i];
            else
                probability += dp[i];
            
            if(i-maxPts >= 0)
                sum -= dp[i-maxPts];
        } 

        return probability;
    }
};
//https://leetcode.com/problems/new-21-game/