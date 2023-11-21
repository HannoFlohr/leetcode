class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_pair = 0, n = nums.size();
        for(int i = 0; i < n/2; i++) {
            max_pair = max(max_pair, nums[i]+nums[n-1-i]);
        }

        return max_pair;
    }
};
//https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/