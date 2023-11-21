class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp (5, 1), dp_before = dp;

        for(int i = 2; i <= n; ++i) {
            int sum_after = 0; 

            for(int j = 3; j >= 0; --j) {
                sum_after += dp_before[j+1];
                dp[j] += sum_after;
            }

            dp_before = dp;
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};
//https://leetcode.com/problems/count-sorted-vowel-strings/