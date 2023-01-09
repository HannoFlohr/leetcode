class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), i = 0;
        vector<int> missing (n);
        
        for (; i < n; ++i) 
            missing[i] = capacity[i] - rocks[i];
        
        sort(missing.begin(), missing.end());
        
        for (i = 0; i < n && additionalRocks >= missing[i]; ++i)
            additionalRocks -= missing[i];
        
        return i;
    }
};
//https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/