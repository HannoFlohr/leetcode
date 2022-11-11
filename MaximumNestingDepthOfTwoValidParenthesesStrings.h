class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int depth = 0;
        
        for(char &c : seq) {
            if(c == '(') depth += 1;
            
            result.push_back(depth % 2);
            
            if(c == ')') depth -= 1;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/