class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count_target_in_nums = 0, index = 0;
        for(int n : nums) {
            if(n == target) {
                count_target_in_nums++;
            }
            else if(n < target) {
                index++;
            }
        }
        
        vector<int> indices (count_target_in_nums);
        iota(indices.begin(), indices.end(), index);
        return indices;
    }
};
//https://leetcode.com/problems/find-target-indices-after-sorting-array/