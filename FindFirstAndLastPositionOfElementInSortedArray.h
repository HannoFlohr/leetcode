class Solution {

int lower_bound(vector<int>& nums, int target) {
    int mid, left=0, right=nums.size()-1;
    while(left<=right) {
        mid = (right+left)/2;
        if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return left;
}
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = lower_bound(nums, target+1)-1;
        
        if(first < nums.size() && nums[first] == target)
            return {first, last};
        else
            return {-1, -1};
    }
};
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/