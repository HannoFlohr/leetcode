class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = 0, leftSum = 0, rightSum = 0;
        
        for(auto n:nums) rightSum += n;
        
        while(pivot<nums.size()) { 
            rightSum -= nums[pivot];
            
            if(leftSum == rightSum) return pivot;
            
            leftSum += nums[pivot++];
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/find-pivot-index/