class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        for(int n : nums) {
            if(n < k) {
                ++operations;
            }
        }
        return operations;
    }
};
//https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/