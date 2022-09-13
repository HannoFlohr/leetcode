class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int ops=nums.size()-1; ops>0; ops--)
            for(int i=0; i<ops; i++) 
                nums[i] = (nums[i]+nums[i+1]) % 10;

        return nums[0];    
    }
};
//https://leetcode.com/problems/find-triangular-sum-of-an-array/