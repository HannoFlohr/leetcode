class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool remove_available = true;
        int last = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= last) {
                if(!remove_available) return false;
                remove_available = false;
                
				/*
				check which element can be "removed" and update if necessary
				usually we want to remove the bigger element if possible
				e.g. when analyzing [4,2] of [1,4,2,3] -> remove the 4 ('last' stays the same)
					 but for [3,4,2,3] -> we have to remove the 2 because its also smaller than nums[i-2] (update 'last')
				*/
                if(i==1 || nums[i] > nums[i-2])
                    last = nums[i];
            }
            else
                last = nums[i]; 
        }
        
        return true;
    }
};
//https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/