class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers (n);
        ugly_numbers[0] = 1;

        int multiplier2 = 0, multiplier3 = 0, multiplier5 = 0, value2 = 2, value3 = 3, value5 = 5;

        for(int i=1; i<n; i++) {
            ugly_numbers[i] = min({value2, value3, value5}); 
            if(ugly_numbers[i] == value2) 
                value2 = ugly_numbers[++multiplier2] * 2;
            if(ugly_numbers[i] == value3) 
                value3 = ugly_numbers[++multiplier3] * 3;
            if(ugly_numbers[i] == value5) 
                value5 = ugly_numbers[++multiplier5] * 5;
        }

        return ugly_numbers[n-1]; 
    }
};
//https://leetcode.com/problems/ugly-number-ii/