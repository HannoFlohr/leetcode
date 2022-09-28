class Solution {
public:
    int jump(vector<int>& nums) {
        int pos=0, jumps=0, reachable=0, i=0;
        
        while(pos < nums.size()-1) {
            reachable = max(reachable, i+nums[i]); 
            if(i==pos) {
                pos = reachable;
                jumps++;
            }
            
            i++;
        }
        
        return jumps;
    }
};
//https://leetcode.com/problems/jump-game-ii/