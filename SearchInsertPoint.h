class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size()-1;
        
        while(left <= right) {
            mid = (left+right)/2;
            
            if(target > nums[mid]) 
                left = mid+1;
            else
                right = mid-1;
        }
        
        return left;
    }
};
//https://leetcode.com/problems/search-insert-position/