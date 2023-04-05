class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, mid, right = n-1, result;

        while(left < right) {
            mid = left + (right - left) / 2;

            if( (mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1]) ) 
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
//https://leetcode.com/problems/single-element-in-a-sorted-array/

/* O(n) approaches

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(size_t i=0; i<nums.size()-1; i+=2) 
            if(nums[i] != nums[i+1]) 
                return nums[i];

        return nums.back();
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        size_t i=1;
        for( ; i<nums.size(); i+=2) {
            if(nums[i-1] == nums[i]) continue;
        
            if(i==1) 
                return nums[0];
            else if(i==nums.size()-1)
                return nums[i];
            else {
                if(nums[i-1] == nums[i-2]) 
                    return nums[i];
                else 
                    return nums[i-1];
            }
        }

        //if i is still 1, the vector contains only one element
        //otherwise loop finished without result -> last element is the single element
        return i==1 ? nums[0] : nums[nums.size()-1];
    }
};

*/