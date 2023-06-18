class Solution {
long long solve(int cur, const vector<vector<int>>& questions, vector<long long>& dp) {
    //check bounds
	if(cur >= questions.size())
        return 0;
    //computed before, use memoized value
	if(dp[cur] != - 1) 
        return dp[cur];
    //max of 1) solving current question + max value after the penalty for using current question or 2) skipping current question  
    return dp[cur] = max( questions[cur][0] + solve(cur + questions[cur][1] + 1, questions, dp),
                            solve(cur+1, questions, dp) );
}

public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp (questions.size(), -1LL);
        return solve(0, questions, dp);
    }
};
//https://leetcode.com/problems/solving-questions-with-brainpower/