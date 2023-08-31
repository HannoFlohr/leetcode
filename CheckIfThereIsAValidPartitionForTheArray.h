class Solution {
private:
    bool checkIfValidPartition(const vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        if(index == n) //end reached
            return true;
        if(dp[index] != -1) //checked already
            return dp[index];

        //condition 1
        if(index+1 < n && nums[index] == nums[index+1]) {
            if(checkIfValidPartition(nums, index+2, dp))
                return true;
            //condition 2
            if(index+2 < n && nums[index] == nums[index+2] && checkIfValidPartition(nums, index+3, dp))
                return true;
        } 
        //condition 3
        if(index+2 < n && nums[index] == nums[index+1]-1 && nums[index] == nums[index+2]-2 && checkIfValidPartition(nums, index+3, dp))
            return true;

        return dp[index] = false;
    }

public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        return checkIfValidPartition(nums, 0, dp);
    }
};
//https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/