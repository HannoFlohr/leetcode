class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};
        
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0) 
                result.push_back(abs(nums[i])); 
            
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]; 
        }
        
        return result;
    }
};
//https://leetcode.com/problems/find-all-duplicates-in-an-array/

/*
all numbers in the array are between 1 and n

loop through all nums[i] and mark encountered numbers at their index nums[nums[i]-1] negative 
if a negative number is encountered, a duplicate is found -> add to result vector 
*/