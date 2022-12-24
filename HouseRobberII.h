class Solution {
private: 
    int rob(vector<int>& nums, bool start) {
        int x = 0, y = 0, z;
        
        for(int i=start; i<nums.size()-(!start); i++){
            z = x;
            x = max(y + nums[i], x);
            y = z;
        }

        return x;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(rob(nums, 0), rob(nums, 1));
    }
};
//https://leetcode.com/problems/house-robber-ii/