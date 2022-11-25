class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> subsets = {{}};
        int same_number, subset_size_before;
        vector<int> cur_set;
        
        for(int i=0; i<nums.size(); i+=same_number) {
            same_number = 0;
            subset_size_before = subsets.size();
            
            //count elements equal to the current one
            while(same_number + i < nums.size() && nums[same_number + i] == nums[i])
                same_number++;
            
            //loop through all subsets
            for(int j=0; j<subset_size_before; j++) {
                cur_set = subsets[j];
                
                //add the current nums[i] 1-same_number times consecutively to these subsets
                for(int k=0; k<same_number; k++) {
                    cur_set.push_back(nums[i]);
                    subsets.push_back(cur_set);
                }
            }
        }
        
        return subsets;
    }
};
//https://leetcode.com/problems/subsets-ii/

/* adapted approach from 'Subsets' 

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> subs = {{}};
        
        for(int i=0; i<nums.size(); i++) {
            vector<vector<int>> subsTmp = subs;
            
            for(int j=0; j<subsTmp.size(); j++)
                subsTmp[j].push_back(nums[i]);
            for(int j=0; j<subsTmp.size(); j++)
                subs.push_back(subsTmp[j]);
        }
        
        set<vector<int>> subsets (subs.begin(), subs.end());
        subs.clear();
        copy(subsets.begin(), subsets.end(), back_inserter(subs));
        
        return subs;
    }
};

/*
