class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, pos = 0, high = nums.size()-1;
        
        while(pos <= high) {
            if(nums[pos] == 0)
                swap(nums[pos++], nums[low++]);
            else if(nums[pos] == 1)
                pos++;
            else
                swap(nums[pos], nums[high--]);
        }
    }
};
//https://leetcode.com/problems/sort-colors/