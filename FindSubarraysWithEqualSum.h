class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> sums;
        int sum = nums[0]+nums[1];
        sums.insert(sum);

        for(int i = 1; i< nums.size()-1; i++) {
            sum += nums[i+1] - nums[i-1];
            if(sums.find(sum) != sums.end()) {
                return true;
            }
            sums.insert(sum);
        }

        return false;
    }
};
//https://leetcode.com/problems/find-subarrays-with-equal-sum/