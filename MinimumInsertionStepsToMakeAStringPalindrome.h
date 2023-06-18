class Solution {
public:
    int minInsertions(string s) {
        const unsigned int n = s.length();
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0));

        for(size_t i = 0; i < n; ++i)
            for(size_t j = 0; j < n; ++j)
                dp[i+1][j+1] = s[i] == s[n-1-j] ? dp[i][j]+1 : max(dp[i][j+1], dp[i+1][j]);
 
        return n - dp[n][n];
    }
};
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

/*
split string in two parts
find split strings with longest common symmetrical sequence (-> least letters need to be inserted) 

dp(i,j) is length of longest common symmetrical sequence of i first letters in first string and j last letters in second string
result is than the length of the string n - dp(n,n) 
*/

/* first approach, passes 13/58 testcases

class Solution {
private: 
    void minInsertions(const string& s, size_t left, size_t right, unsigned int insertions, unsigned int& min_insertions) {
        if(insertions >= min_insertions)
            return;

        while(left < right && s[left] == s[right])
            left++, right--;

        if(left >= right) {
            min_insertions = min(min_insertions, insertions);
            return;
        }

        minInsertions(s, left+1, right, insertions+1, min_insertions);
        minInsertions(s, left, right-1, insertions+1, min_insertions);
    }

public:
    int minInsertions(string s) {
        unsigned int min_insertions = s.size();
        minInsertions(s, 0, s.size()-1, 0, min_insertions);
        return min_insertions;
    }
};*/