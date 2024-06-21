class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long max_happiness = 0;
        for(int i = 0; i < k; ++i) {
            happiness[i] = max(happiness[i]-i, 0);
            max_happiness += happiness[i];
        }
        return max_happiness;
    }
};
//https://leetcode.com/problems/maximize-happiness-of-selected-children/