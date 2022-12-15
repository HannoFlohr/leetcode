class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-2] < nums[nums.size()-1]) return nums.size()-1;

        int left = 1, mid, right = nums.size()-2;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] < nums[mid-1])
                right = mid - 1;
            else if(nums[mid] < nums[mid+1])
                left = mid + 1;
        }

        return -1;
    }
};
//https://leetcode.com/problems/find-peak-element/