class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> difference (26,0);
        for(int i = 0; i < s.size(); ++i) {
            difference[s[i]-'a'] = abs(difference[s[i]-'a'] - i);
            difference[t[i]-'a'] = abs(difference[t[i]-'a'] - i);
        }
        return accumulate(difference.begin(), difference.end(), 0);
    }
};
//https://leetcode.com/problems/permutation-difference-between-two-strings/