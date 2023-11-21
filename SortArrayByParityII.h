class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        const int n = nums.size();

        for(int even = 0, odd = 1; even < n; even += 2, odd+=2) {
            while(even < n && nums[even] % 2 == 0) {
                even += 2;
            } 
            while(odd < n && nums[odd] % 2 == 1) {
                odd += 2;
            } 
            if(even < n) {
                swap(nums[even], nums[odd]);
            }
        }

        return nums;
    }
};
//https://leetcode.com/problems/sort-array-by-parity-ii/