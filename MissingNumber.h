class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, sum = nums.size();
        
        for(auto n:nums) {
            sum ^= n;
            sum ^= i++;
        }
        
        return sum;
    }
};
//https://leetcode.com/problems/missing-number/

/*
XORing all nums[i] and all i=0..n is equal to 
XORing every number, except the missing one, twice (cancelling out the duplicates as n XOR n == 0) 
*/