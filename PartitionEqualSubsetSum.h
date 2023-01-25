class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = reduce(nums.begin(), nums.end());
        
        //need even sum to partition equally
        if(sum % 2 != 0) return false;
        
        //both partitions need to sum up to sum/2;
        sum /= 2;

        vector<bool> dp (sum+1, false); //dp[i] is true if i can be summed up by some of the nums
        dp[0] = true;
        for(auto &num : nums) 
            for(int i=sum; i>=num; i--) 
                if(i >= num)
                    dp[i] = dp[i] || dp[i - num];

        return dp[sum];
    }
};
//https://leetcode.com/problems/partition-equal-subset-sum/

//0-1 knapsack problem -> https://en.wikipedia.org/wiki/Knapsack_problem