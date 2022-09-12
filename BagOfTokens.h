class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        const int n = tokens.size();
        int left = 0, right = n;
        
        while(left < right) {
            if(power >= tokens[left])
                power -= tokens[left++];
            else if(left - (n - right) && right > left + 1)
                power += tokens[--right];
            else
                break;
        }
        
        return left - n + right;
    }
};
//https://leetcode.com/problems/bag-of-tokens/