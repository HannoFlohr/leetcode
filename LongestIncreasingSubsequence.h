class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        
        for(int n : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), n);
            if(it == lis.end())
                lis.push_back(n);
            else 
                *it = n;
        }
        
        return lis.size();
    }
};
//https://leetcode.com/problems/longest-increasing-subsequence/