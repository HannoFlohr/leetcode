class Solution {
public:
    int minOperations(const vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if(target == 0) {
            return nums.size();
        }

        int max_length = 0;
        sum = 0;

        for(int end = 0, start = 0; end < nums.size(); ++end) {
            sum += nums[end];

            while((sum > target) && (start <= end)) {
                sum -= nums[start];
                ++start;
            }

            if(sum == target) {
                max_length = max(max_length, end-start+1);
            }
        }

        return max_length == 0 ? -1 : nums.size()-max_length;
    }
};
//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/