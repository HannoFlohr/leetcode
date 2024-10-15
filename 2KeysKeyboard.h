class Solution {
public:
    int minSteps(int n) {
        vector<int> dp (n+1, 0);

        for(int i = 2; i <= n; ++i) {
            dp[i] = i;

            for(int j = i/2; j > 1; --j) {
                //can sequence of length j be pasted multiple times to get sequence of length i?
                if(i % j == 0) {
                    //need to copy sequence j and paste it (i/j)-1 times
                    dp[i] = dp[j] + (i/j);
                    break;
                }
            }
        }

        return dp[n];
    }
};
//https://leetcode.com/problems/2-keys-keyboard/