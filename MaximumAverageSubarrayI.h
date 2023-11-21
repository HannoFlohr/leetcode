class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin()+k, 0);
        int max_sum = sum;

        for(int i = k ; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            max_sum = max(max_sum, sum);
        }

        return (double)max_sum/k;
    }
};
//https://leetcode.com/problems/maximum-average-subarray-i/