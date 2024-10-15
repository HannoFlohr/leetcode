class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = accumulate(rolls.begin(), rolls.end(), 0);
        int missing = mean * (n+m) - sum;

        if(missing < n || missing > 6*n)
            return {};

        int parts = missing/n, remainder = missing%n;
        vector<int> result (n, parts);
        for(int i = 0; i < remainder; ++i) 
            ++result[i];

        return result;
    }
};
//https://leetcode.com/problems/find-missing-observations/