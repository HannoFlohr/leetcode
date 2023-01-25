class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum_all_nums = 0, sum_max = INT_MIN, sum_min = INT_MAX, cur_max = 0, cur_min = 0;

        for(auto & num : nums) {
            cur_max = max(num, cur_max + num);
            sum_max = max(sum_max, cur_max);
            cur_min = min(num, cur_min + num);
            sum_min = min(sum_min, cur_min);
        
            sum_all_nums += num;
        }

        return sum_max > 0 ? max(sum_max, sum_all_nums - sum_min) : sum_max;
    }
};
//https://leetcode.com/problems/maximum-sum-circular-subarray/

//https://en.wikipedia.org/wiki/Maximum_subarray_problem