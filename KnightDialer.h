class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9+7;
        const vector<vector<int>> next_dial = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<int> goto_cur (10,1);

        while(--n > 0) { 
            vector<int> goto_next (10,0);

            for(int i = 0; i < 10; i++) {
                if(goto_cur[i] == 0) {
                    continue;
                }

                for(int n : next_dial[i]) {
                    goto_next[n] += goto_cur[i]; 
                    goto_next[n] %= MOD;
                }
            }

            goto_cur = goto_next;
        }

        int sum = 0;
        for(int i : goto_cur) {
            sum = (sum + i) % MOD;
        }
        return sum;
    }
};
//https://leetcode.com/problems/knight-dialer/