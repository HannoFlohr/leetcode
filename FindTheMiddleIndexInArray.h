class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int middleIndex = 0, leftSum = 0, rightSum = 0;
        
        for(auto n:nums) rightSum += n;
        
        while(middleIndex<nums.size()) { 
            rightSum -= nums[middleIndex];
            
            if(leftSum == rightSum) return middleIndex;
            
            leftSum += nums[middleIndex++];
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/find-the-middle-index-in-array/