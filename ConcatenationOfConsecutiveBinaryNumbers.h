class Solution {    
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9+7;
        long result = 0;
        
        for(int i=1; i<=n; i++) {
            int bits = log2(i)+1;
            result = ((result << bits) % MOD + i) % MOD;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/