class Solution {
public:
    /*
    binary search, with an extra step
    compare the target value and the value at the current mid point with nums[0]
    if value[mid]<num[0] and value[target]<nums[0] or both '>' instead, take +/-INT_MAX as compare value
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid, cur; 
        
        while(left < right) {
            mid = (left+right)/2;
            
            cur = ((nums[mid]<nums[0]) == (target<nums[0])) ? nums[mid] : (target<nums[0]) ? INT_MIN : INT_MAX;
            
            if(cur<target)
                left = mid + 1;
            else if(cur>target)
                right = mid;
            else
                return mid;
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/search-in-rotated-sorted-array/