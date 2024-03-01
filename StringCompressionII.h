class Solution {
private:
    const static int MAX_LENGTH = 101;
    
    int digits(int x) {
        if(x == 1)
            return 0;
        if(x < 10)
            return 1;
        if(x < 100)
            return 2;
        return 3;
    }
    
    int solve(int start, int k, const string& s, const int n, vector<vector<int>>& dp) {
        if(k < 0) {
            return MAX_LENGTH;
        }
        if(start >= n || n-start <= k) {
            return 0;
        }
        
        int &result = dp[start][k];
        if(result != -1) {
            return result;
        }
        result = MAX_LENGTH;
        
        vector<int> count (26,0);
        for(int i = start, most = 0; i < n; i++) {
            most = max(most, ++count[s[i] - 'a']); 
            result = min(result, 1 + digits(most) + solve(i + 1, k - (i - start + 1 - most), s, n, dp));
        }
        
        return result;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        //dp[start][k] means minimal coding size for substring s[start:], removing at most k chars 
        vector<vector<int>> dp = vector<vector<int>>(MAX_LENGTH, vector<int>(MAX_LENGTH, -1));
        int n = s.size();
        return solve(0, k, s, n, dp);
    }
};
//https://leetcode.com/problems/string-compression-ii/