class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0, right = 0, n = nums.size(), max_difference = 2*k;
        while(right < n) {
            if(nums[right] - nums[left] > max_difference)
                ++left;
            ++right;
        }

        return right-left;    
    }
};
//https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/