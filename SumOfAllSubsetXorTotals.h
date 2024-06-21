class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xor_sum = 0;
        for(int num : nums) {
            xor_sum |= num;
        }
        return xor_sum << (nums.size()-1);
    }
};
//https://leetcode.com/problems/sum-of-all-subset-xor-totals/