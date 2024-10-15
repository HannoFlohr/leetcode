class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int partitions = 0, start = 0, end = 0, n = nums.size();

        while(start < n) {
            while(end < n && nums[end] <= nums[start] + k)
                ++end;
            
            ++partitions;
            start = end;
        }

        return partitions;
    }
};
//https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/