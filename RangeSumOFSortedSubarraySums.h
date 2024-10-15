class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9+7;
        multiset<int> sums;

        for(int i = 0; i < n; ++i) {
            int sum = nums[i];
            sums.insert(sum);
            for(int j = i+1; j < n; ++j) {
                sum += nums[j];
                sums.insert(sum);
            }
        }

        int sum = 0, count = 0;
        for(int s : sums) {
            ++count;
            if(count < left) {
                continue;
            }
            if(count > right) {
                break;
            }
            sum = (sum + s) % MOD;
        }

        return sum;
    }
};
//https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/