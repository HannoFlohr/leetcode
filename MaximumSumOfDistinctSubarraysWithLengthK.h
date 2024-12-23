class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), duplicates = 0;
        long long max_sum = 0, sum = 0;
        unordered_map<int,int> frequency;
        

        for(int right = 0, left = 0; right < n; ++right) {
            //add number at current index to the window
            sum += nums[right];
            ++frequency[nums[right]];
            if(frequency[nums[right]] == 2)
                ++duplicates; 

            //size of window too short
            if(right < k-1)
                continue;
            //if there are no duplicates in current window, update max sum
            if(duplicates == 0)
                max_sum = max(max_sum, sum);

            //remove outgoing number from window
            sum -= nums[left];
            --frequency[nums[left]];
            if(frequency[nums[left]] == 1)
                --duplicates;
            ++left;
        }


        return max_sum;
    }
};
//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/