class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> values;
        while(n > 0) {
            values.push_back(n % 10);
            n /= 10;
        }
        
        int sum = 0;
        bool add = true; 
        for(auto it = values.rbegin(); it != values.rend(); it++) { 
            if(add) {
                sum += *it;
            }
            else {
                sum -= *it;
            }
            add = !add;
        }

        return sum;
    }
};
//https://leetcode.com/problems/alternating-digit-sum/