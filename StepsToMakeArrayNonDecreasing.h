class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int steps = 0;
        
        vector<int> stack, dp(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            while(!stack.empty() && nums[i] > nums[stack.back()]) {
                dp[i] = max( ++dp[i], dp[stack.back()]);
                stack.pop_back();
                steps = max(steps, dp[i]);
            }
            stack.push_back(i);
        }
        
        return steps;
    }
};
//https://leetcode.com/problems/steps-to-make-array-non-decreasing/

/*
iterate 'nums' reversely
dp[i] is the number of elements nums[i] can remove to its right

e.g. nums = [5,3,4,4,7,3,6,11,8,5,11]
reverse = [11,5,8,11,6,3,7,4,4,3,5]
first 11 can be used to remove 5,8 in two steps (dp[i] = 2)
second 11 can be used to rmove 6,3 in two steps (dp[i] = 2)
the 7 can be used to remove 4,4,3 in three steps (dp[i] = 3)
-> 3 steps are needed

if nums[i] is greater than the last element on the stack: 
update dp[i] to max of dp[i]+1 and dp[last_stack_element] 
*/
