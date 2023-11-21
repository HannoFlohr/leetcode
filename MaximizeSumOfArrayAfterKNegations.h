class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() && k > 0 && nums[i] < 0; ++i) {
            nums[i] = -nums[i];
            --k;
        }

        return accumulate(nums.begin(), nums.end(), 0) - (k%2) * (*min_element(nums.begin(), nums.end()) * 2);
    }
};
//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

/*
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() && k > 0; ++i) {
            if(nums[i] >= 0) {
                break;
            }
            nums[i] = -nums[i];
            --k;
        }

        sort(nums.begin(), nums.end());

        int sum = nums[0];
        if(k%2 == 1) {
            sum *= -1;
        }

        for(int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
        }

        return sum;
    }
};
*/