class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), left = 0, mid, right = 1000000, count;
        while(left < right) {
            mid = (left + right) / 2;
            count = 0;

            for(int i = 0, j = 0; i < n; ++i) {
                while(j < n && nums[j] - nums[i] <= mid) {
                    ++j;
                }
                count += j - i - 1;
            }

            if(count < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};
//https://leetcode.com/problems/find-k-th-smallest-pair-distance/