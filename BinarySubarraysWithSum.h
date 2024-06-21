class Solution {
private:
    int countSubarraysWithSum(const vector<int>& nums, int goal) {
        if(goal < 0) {
            return 0;
        }

        int counter = 0;

        for(int end = 0, start = 0; end < nums.size(); ++end) {
            goal -= nums[end];
            while(goal < 0) {
                goal += nums[start];
                start++;
            }
            counter += end-start+1;
        }
        return counter;
    }
	
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarraysWithSum(nums, goal) - countSubarraysWithSum(nums, goal-1);
    }
};
//https://leetcode.com/problems/binary-subarrays-with-sum/