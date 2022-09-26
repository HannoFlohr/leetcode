class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        
        for(int i=0; i<n; i++) {
            int index = abs(nums[i])-1;
            if(nums[index]>0) nums[index] = -nums[index];
        }
        
        vector<int> result;
        for(int i=0; i<n; i++)
            if(nums[i] > 0)
                result.push_back(i+1);
        
        return result;
    }
};
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

/*
first loop: negate the values at positions of numbers that appear in an array
second loop: values of nums[i] still positive signal a missing number i+1
*/