class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        auto target = 0;
        for(const auto &num : nums)
            target = (target + num) % p;
        if(target == 0) 
            return 0;

        unordered_map<int,int> most_recent_position_mod = {{0,-1}};
        int sum = 0, complement, subarray_delete_size = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % p;
            complement = (p - target + sum) % p;

            if(most_recent_position_mod.find(complement) != most_recent_position_mod.end())
                subarray_delete_size = min(subarray_delete_size, i - most_recent_position_mod[complement]);

            most_recent_position_mod[sum] = i;
        }

        return subarray_delete_size >= nums.size() ? -1 : subarray_delete_size;
    }
};
//https://leetcode.com/problems/make-sum-divisible-by-p/