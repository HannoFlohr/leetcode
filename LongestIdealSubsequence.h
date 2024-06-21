class Solution {
public:
    int longestIdealString(string s, int k) {
        int cur, max_index, left_limit, right_limit;
        vector<int> dp (27,0); //dp[i] : longest ideal string ending at char i

        for(int i = s.size()-1; i >= 0; --i) {
            cur = s[i]-'a';
            //limits for the range of possible previous characters
            left_limit = max((cur-k), 0);
            right_limit = min((cur+k), 26);
            //find max element in that range
            max_index = *max_element(dp.begin()+left_limit, dp.begin()+right_limit+1);
            //update current character
            dp[cur] = max_index+1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
//https://leetcode.com/problems/longest-ideal-subsequence/