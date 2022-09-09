class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result (nums.size());
        int left=0, right=nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--) 
            result[i] = (abs(nums[right]) > abs(nums[left])) ? (nums[right] * nums[right--]) : (nums[left] * nums[left++]);
           
        return result;
    }
};
//https://leetcode.com/problems/squares-of-a-sorted-array/