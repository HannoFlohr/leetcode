class Solution {
public:
    int rob(vector<int>& nums) {
        int x = 0, y = 0, z;
        
        for(auto &n : nums){
            z = x;
            x = max(y + n, x);
            y = z;
        }

        return x;
    }
};
//https://leetcode.com/problems/house-robber/