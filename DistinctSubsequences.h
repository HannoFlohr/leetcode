class Solution {
public:
    /*
        if char s[i-1] equals t[j-1] we can
        - either include s[i-1] in the subsequence (dp[i-1][j-1])
        - or exclude it from the subsequence (dp[i-1][j])
        if chars are not equal we can only exclude s[i-1] 

        we only need to remember the last level i, so we can use two 1 dimensional arrays
        dp[i-1][j] is always used so we can copy that
        and update if we want to include a matching char in s[i-1]
    */
    int numDistinct(string s, string t) {
        const int &ssize = s.size(), &tsize = t.size();
        if(tsize > ssize) 
            return 0;
        //dp[i][j]: number of distinct subsequences of s[0..i-1] equal to t[0..j-1]
        vector<unsigned int> previous (ssize+1, 0);
        vector<unsigned int> current (ssize+1, 0);
        previous[0] = 1;

        for(int i = 1; i <= ssize; ++i) {
            current = previous;
            
            for(int j = 1; j <= tsize; ++j) {
                if(s[i-1] == t[j-1])
                    current[j] += previous[j-1];
            }

            swap(previous, current);
        }

        return previous[tsize];
    }
};
//https://leetcode.com/problems/distinct-subsequences/