class Solution {
private:
    int lower, upper;
    vector<long> prefix_sum;

    int mergeSort(int left, int right) { 
        if(right - left <= 1) return 0;

        int mid = left + (right-left) / 2;
        int count = mergeSort(left, mid) + mergeSort(mid, right); 

        for(int i=left; i<mid; i++) {
            auto lb = lower_bound(prefix_sum.begin() + mid, prefix_sum.begin() + right, prefix_sum[i] + lower);
            auto ub = upper_bound(prefix_sum.begin() + mid, prefix_sum.begin() + right, prefix_sum[i] + upper);
            count += ub - lb;
        }

        inplace_merge(prefix_sum.begin() + left, prefix_sum.begin() + mid, prefix_sum.begin() + right);

        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        prefix_sum = vector<long>(nums.size()+1, 0);
        for(size_t i=0; i<nums.size(); i++) 
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        
        return mergeSort(0, nums.size()+1); 
    }
};
//https://leetcode.com/problems/count-of-range-sum/

/*
first compute prefix sums for all nums 
sum of a subarray nums[i:j] = prefix_sum[j]-prefix_sum[i] 

use merge sort approach, with counting, to find such subarrays that are in [lower,upper] 

pairs in left half and right half are counted using recursive calls each
to find the pairs that are in both halves:
- for each left in prefix_sum[left:mid]
	- find lower bound in [mid:right] that meets condition right-left >= [lower,upper]
	- find upper bound in [mid:right] that meets condition right-left > [lower,upper]
	- upper_bound - lower_bound than is the number of valid range sums
*/