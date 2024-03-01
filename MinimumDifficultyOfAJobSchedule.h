class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        const int n = jobDifficulty.size();
        if(n < days) {
            return -1;
        }
        vector<int> dp (n, 1000), dp2 (n), stack;
        
        for(int d = 0; d < days; ++d) {
            stack.clear();

            for(int i = d; i < n; ++i) {
                if(i > 0)
                    dp2[i] = dp[i-1] + jobDifficulty[i];
                else 
                    dp2[i] = jobDifficulty[i];
                
                while(stack.size() && jobDifficulty[stack.back()] <= jobDifficulty[i]) {
                    int j = stack.back(); 
                    stack.pop_back();
                    dp2[i] = min(dp2[i], dp2[j] - jobDifficulty[j] + jobDifficulty[i]);
                }
                
                if(stack.size())
                    dp2[i] = min(dp2[i], dp2[stack.back()]);
                
                stack.push_back(i);
            }
            
            swap(dp, dp2);
        }
        
        return dp[n-1];
    }
};
//https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/