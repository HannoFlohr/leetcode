class Solution {
private:
    int maxSubArray(vector<int> &nums, int left, int right) {
        if(left > right) return INT_MIN;
        
        int mid = (left+right)/2, sumleft = 0, sumright = 0;
        
        for(int i=mid-1, sum=0; i>=left; i--) {
            sum += nums[i];
            sumleft = max(sumleft, sum);
        }
        for(int i=mid+1, sum=0; i<=right; i++) {
            sum += nums[i];
            sumright = max(sumright, sum);
        }
        
        return max( {maxSubArray(nums, left, mid-1), maxSubArray(nums, mid+1, right), sumleft+nums[mid]+sumright } );
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
};
//https://leetcode.com/problems/maximum-subarray/

/* above approach using divide and conquer;

using Kadanes ALgorihm: 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = curSum;
        
        for(int i=1; i<nums.size(); i++) {
            curSum = max(nums[i], curSum+nums[i]);
            maxSum = max(maxSum, curSum);
        }
        
        return maxSum;
    }
};

*/