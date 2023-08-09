class Solution {
private: 
    void reduce(string& s) {
        const regex re("(.)\\1*");
        s = std::regex_replace(s, re, "$1");
    }

public:
    int strangePrinter(string s) {
        reduce(s);
        
        const int& n = s.size();
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0)); //dp[i][j]: minimum prints for substring from i to j
        int end, prints;

        for(int length = 0; length < n; ++length) {
            for(int start = 0; start < n - length; ++start) {
                end = start + length;
                dp[start][end] = length + 1;

                for(int next = start+1; next <= end; ++next) {
                    prints = dp[start][next-1] + dp[next][end]; 
                    if(s[next-1] == s[end])
                        --prints;
                    
                    dp[start][end] = min(dp[start][end], prints);
                }
            }
        }

        return dp[0][n-1];
    }
};
//https://leetcode.com/problems/strange-printer/