class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        
        for(int i=0; i<n; i++)
            if(nums[i] != i+1)
                return i+1;
        
        return n+1;
    }
};
//https://leetcode.com/problems/first-missing-positive/

/*
array with length n; first missing positive integer must be in [1,..,n+1]
values < 1 and > n+1 can be ignored

first loop through array and put all valid numbers in its place so that nums[i] = i+1
than look for a nums[i] != i+1 to find the solution
*/