class Solution {
public:
    int rob(vector<int>& nums) {
        int max_money = 0, second_best = 0, x;
        
        for(int num : nums){
            x = max_money;
            max_money = max(max_money, second_best + num);
            second_best = x;
        }

        return max_money;
    }
};
//https://leetcode.com/problems/house-robber/