class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0;
        deque<int> min_n, max_n;

        for( ; j < nums.size(); ++j) {
            while(!max_n.empty() && nums[j] > max_n.back()) {
                max_n.pop_back();
            }
            while(!min_n.empty() && nums[j] < min_n.back()) {
                min_n.pop_back();
            }

            max_n.push_back(nums[j]);
            min_n.push_back(nums[j]);

            if(max_n.front() - min_n.front() > limit) {
                if(max_n.front() == nums[i]) {
                    max_n.pop_front();
                }
                if(min_n.front() == nums[i]) {
                    min_n.pop_front();
                }
                ++i;
            }
        }    

        return j - i;
    }
};
//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/