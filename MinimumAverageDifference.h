class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), min_diff_index, min_diff = INT_MAX, avg1, avg2; 
        long total_sum = 0, cur_sum = 0;
        
        for(auto &i: nums) total_sum += i;
        
        for(int i=0; i<n; i++) {
            cur_sum += nums[i]; 
            avg1 = cur_sum / (i+1);
            
            if(i == n-1) {
                if(avg1 < min_diff) return n-1;
                else break;
            }
            
            avg2 = (total_sum - cur_sum) / (n-i-1);
            
            if(abs(avg1 - avg2) < min_diff) {
                min_diff = abs(avg1 - avg2);
                min_diff_index = i;
            }
        }
        
        return min_diff_index;
    }
};
//https://leetcode.com/problems/minimum-average-difference/

/*
- calculate total sum of nums
for each i in nums: 
	- calculate sum till i-th index and sum from i+1 to n-i-1
	- calculate absolute difference between these sums and track the minimum difference and index 
*/