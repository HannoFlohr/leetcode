class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0, count;
        long diff;
        vector<unordered_map<long, int>> dp (nums.size()); //dp[i][d]: number of subsequences that end with nums[i] and common difference d
        
        for(int i=1; i<nums.size(); i++) 
            for(int j=0; j<i; j++) {
                diff = (long) nums[i] - nums[j];
                count = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += count + 1;
                result += count;
            }
        
        return result;
    }
};
//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/