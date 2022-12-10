class Solution {
public:
    int commonFactors(int a, int b) {
        if(a > b) swap(a,b);
        
        int common_factors = 0;
        for(int factor=1; factor<=a; factor++)
            if(a%factor==0 && b%factor==0) 
                common_factors++;
        
        return common_factors;
    }
};
//https://leetcode.com/problems/number-of-common-factors/