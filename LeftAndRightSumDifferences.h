class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n = nums.size();
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0); 

        vector<int> answer (n);
        for(int i = 0; i < n; ++i) {
            rightSum -= nums[i];
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }   

        return answer; 
    }
};
//https://leetcode.com/problems/left-and-right-sum-differences/