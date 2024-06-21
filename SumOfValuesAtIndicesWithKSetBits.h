class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(bitset<17>(i).count() == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};
//https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/