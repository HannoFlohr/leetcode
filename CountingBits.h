class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        
        int ones, x;
        for(int i=0; i<=n; i++) {
            x = i;
            ones = 0;
            
            while(x) {
                ones += x%2;
                x /= 2;
            }
            
            result.push_back(ones);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/counting-bits/