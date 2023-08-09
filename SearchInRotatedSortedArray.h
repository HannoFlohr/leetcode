class Solution {
public:
class Solution {
public:
    /*
    binary search, with an extra step
    compare the target value and the value at the current mid point with nums[0]
    if value[mid]<num[0] and value[target]<nums[0] or both '>' instead, take +/-INT_MAX as compare value
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid, cur_value; 
        
        while(left < right) {
            mid = (left + right) / 2;
            
            if((nums[mid] < nums[0]) == (target < nums[0])) 
                cur_value = nums[mid];
            else if(target < nums[0])
                cur_value = INT_MIN;
            else
                cur_value = INT_MAX;

            if(cur_value < target)
                left = mid + 1;
            else if(cur_value > target)
                right = mid;
            else
                return mid;
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/search-in-rotated-sorted-array/