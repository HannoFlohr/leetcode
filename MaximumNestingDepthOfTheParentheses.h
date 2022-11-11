class Solution {
public:
    int maxDepth(string s) {
        int max_nesting_depth = 0, counter = 0;
        
        for(char &c : s) {
            if(c == '(')
                max_nesting_depth = max(max_nesting_depth, ++counter);
            else if(c == ')')
                counter--;
        }
        
        return max_nesting_depth;
    }
};
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/