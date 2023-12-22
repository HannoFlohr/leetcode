class Solution {
public:
    int maxScore(string s) {
        int max_score = 0, n = s.length();
        vector<int> zeros_before (n,0), ones_after (n,0);
        zeros_before[0] = (s[0] == '0');
        ones_after[n-1] = (s[n-1] == '1');

        for(int i = 1; i < n; i++) {
            zeros_before[i] = zeros_before[i-1] + (s[i] == '0');
            ones_after[n-1-i] = ones_after[n-i] + (s[n-1-i] == '1');
        }

        for(int i = 0; i < n-1; i++) {
            max_score = max(max_score, zeros_before[i] + ones_after[i+1]);
        }

        return max_score;
    }
};
//https://leetcode.com/problems/maximum-score-after-splitting-a-string/