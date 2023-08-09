class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int max_count = 0, seed = INT_MAX;
        unordered_map<int,int> values;

        for(const int& n : nums) 
            max_count = max(max_count, ++values[n % space]);
    
        for(const int& n : nums)
            if(values[n % space] == max_count)
                seed = min(seed, n);

        return seed;
    }
};
//https://leetcode.com/problems/destroy-sequential-targets/