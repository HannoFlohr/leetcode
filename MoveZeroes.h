class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        
        //move non zero elements to the start
        for(int i=0; i<nums.size(); i++) 
            if(nums[i] != 0)
                nums[j++] = nums[i];
        
        //fill in zeroes
        for( ; j<nums.size(); j++)
            nums[j] = 0;
    }
};
//https://leetcode.com/problems/move-zeroes/