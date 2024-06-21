class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9+7;
        //base case: number of valid attendance dates for 0 days
        vector<vector<int>> dp_previous (2, vector<int>(3,1));
        
        for(int i = 1; i <= n; ++i) {
            vector<vector<int>> dp_current (2, vector<int>(3,0));

            //loop through all possible states for absences and lates
            //and update the dp bases on the previous dp values and the current state
            for(int a = 0; a < 2; ++a) {
                for(int l = 0; l < 3; ++l) {
                    //choose P
                    dp_current[a][l] += dp_previous[a][2];
                    dp_current[a][l] %= MOD;
                    //choose A
                    if(a > 0) {
                        dp_current[a][l] += dp_previous[a-1][2];
                        dp_current[a][l] %= MOD;
                    }
                    //choose L
                    if(l > 0) {
                        dp_current[a][l] += dp_previous[a][l-1];
                        dp_current[a][l] %= MOD;
                    }
                }
            }

            dp_previous = dp_current;
        }

        return dp_previous[1][2];
    }
};
//https://leetcode.com/problems/student-attendance-record-ii/