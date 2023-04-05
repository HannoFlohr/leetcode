class Solution {
private:
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true, isDecreasing = true;
        
        for(size_t i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) 
                isDecreasing = false;
            else if(nums[i] < nums[i-1]) 
                isIncreasing = false;
        }

        return isIncreasing || isDecreasing;
    }
};
//https://leetcode.com/problems/monotonic-array/

/* first approach

class Solution {
private:
    bool isIncreasing(const vector<int>& nums, size_t i) {
        for( ; i<nums.size(); i++)
            if(nums[i-1] > nums[i])
                return false;
        return true;
    }
    
    bool isDecreasing(const vector<int>& nums, size_t i) {
        for( ; i<nums.size(); i++)
            if(nums[i-1] < nums[i])
                return false;
        return true;
    }

public:
    bool isMonotonic(vector<int>& nums) {
        size_t i = 1;
        while(i < nums.size() && nums[i] == nums[i-1])
            i++;

        if(i == nums.size()) return true;

        return nums[i-1] < nums[i] ? isIncreasing(nums, i+1) : isDecreasing(nums, i+1);
    }
};

*/