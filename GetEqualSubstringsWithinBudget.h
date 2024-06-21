class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int max_length = 0, cost = 0;

        for(int start = 0, end = 0; end < s.size(); ++end) {
            cost += abs(s[end] - t[end]);

            while(cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                ++start;
            }

            max_length = max(max_length, end-start+1);
        }

        return max_length;
    }
};
//https://leetcode.com/problems/get-equal-substrings-within-budget/