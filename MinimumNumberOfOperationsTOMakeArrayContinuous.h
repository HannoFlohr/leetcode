class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int size = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        const int unique_size = nums.size();
        int min_operations = size, end = 0;
        
        for(int start = 0; start < unique_size; start++) {
            while(end < unique_size && nums[end] < nums[start]+size) {
                end++;
            }
            min_operations = min(min_operations, size-end+start);
        }

        return min_operations;
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/