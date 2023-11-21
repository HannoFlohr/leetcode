class Solution {

int lower_bound(const vector<int>& nums, int target, int left, int right) {
    int mid;
    while(left <= right) {
        mid = (right+left)/2;
        if(nums[mid] < target) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return left;
}
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target, 0, nums.size()-1);
        int last = lower_bound(nums, target+1, first, nums.size()-1) - 1;
        
        if(first < nums.size() && nums[first] == target) {
            return {first, last};
        }
        return {-1, -1};
    }
};	
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/