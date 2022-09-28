class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for(int reachable=0; i<nums.size() && i<=reachable; i++) 
            reachable = max(reachable, i + nums[i]);
        
        return i == nums.size(); 
    }
};
//https://leetcode.com/problems/jump-game/