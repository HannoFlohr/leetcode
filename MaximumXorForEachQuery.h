class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int max_xor = pow(2, maximumBit) - 1;
        int cur_xor = 0, n = nums.size();
        vector<int> results (n, 0);

        for(int i = 0; i < n; ++i) {
            cur_xor ^= nums[i];
            results[n-1-i] = cur_xor ^ max_xor;
        }

        return results;
    }
};
//https://leetcode.com/problems/maximum-xor-for-each-query/