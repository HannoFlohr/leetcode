class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        subs.emplace({});
        
        for(int i=0; i<nums.size(); i++) {
            vector<vector<int>> subsTmp = subs;
            
            for(int j=0; j<subsTmp.size(); j++)
                subsTmp[j].push_back(nums[i]);
            for(int j=0; j<subsTmp.size(); j++)
                subs.push_back(subsTmp[j]);
        }
        
        return subs;
    }
};
//https://leetcode.com/problems/subsets/

/*
https://stackoverflow.com/questions/728972/finding-all-the-subsets-of-a-set/729603#729603
*/