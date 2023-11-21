class Solution {
public:
    bool isSubsequence(string s, string t) {
        int found = 0;

        for(int i = 0; i < t.size() && found < s.size(); ++i) {
            if(s[found] == t[i]) {
                ++found;
            }
        }

        return found == s.size();
    }
};
//https://leetcode.com/problems/is-subsequence/

/* first approach, usable for substrings 
class Solution {
private:     
    int isSubsequence(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = 1 + isSubsequence(s, t, i-1, j-1, dp);
        }
        else {
            return dp[i][j] = isSubsequence(s, t, i, j-1, dp);
        }
    }
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) {
            return false;
        }
        vector<vector<int>> dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1, -1));
        return isSubsequence(s, t, s.size(), t.size(), dp) == s.size();
    }
};
*/