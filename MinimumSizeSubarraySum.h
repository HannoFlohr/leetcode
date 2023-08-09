class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, cur_sum = 0, min_length = INT_MAX;

        for(int right = 0; right < nums.size(); ++right) {
            cur_sum += nums[right];

            while(cur_sum >= target) {
                min_length = min(min_length, right-left+1);
                cur_sum -= nums[left];
                left++;
            }
        }

        if(min_length == INT_MAX)
            return 0;
        return min_length;
    }
};
//https://leetcode.com/problems/minimum-size-subarray-sum/