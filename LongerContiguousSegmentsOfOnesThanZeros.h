class Solution {
public:
    bool checkZeroOnes(string s) {
        vector<int> longest (2,0);
        int cur = 1;

        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == s[i-1]) {
                cur++;
                continue;
            }
            
            longest[s[i-1]-'0'] = max(longest[s[i-1]-'0'], cur);
            cur = 1;
        }
        longest[s.back()-'0'] = max(longest[s.back()-'0'], cur);

        return longest[1] > longest[0];
    }
};
//https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/