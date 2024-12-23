class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 1;
        int low = nums[0]-2, high = nums[0]+2, j = 0;

        for(int i = 1; i < nums.size(); ++i) {
            //in current range
            if(nums[i] >= low && nums[i] <= high) {
                low = max(low, nums[i]-2);
                high = min(high, nums[i]+2);
                result += i-j+1;
                continue;
            }
            //not in current range; update
            j = i-1;
            low = nums[i]-2, high = nums[i]+2;
            while(nums[j] >= nums[i]-2 && nums[j] <= nums[i]+2) {
                low = max(low, nums[j]-2);
                high = min(high, nums[j]+2);
                --j;
            }
            ++j;
            result += i-j+1;
        }

        return result;
    }
};
//https://leetcode.com/problems/continuous-subarrays/