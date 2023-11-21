class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int n = nums.size();
        long long count = 0, sum = 0;

        for(int start = 0, end = 0; end < n; end++) {
            sum += nums[end];
            
            while(sum * (end-start+1) >= k) {
                sum -= nums[start];
                start++;
            }

            count += end-start+1;            
        }

        return count;
    }
};
//https://leetcode.com/problems/count-subarrays-with-score-less-than-k/