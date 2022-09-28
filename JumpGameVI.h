class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp (nums.size(),0);
        dp[0] = nums[0];
        
        //double ended queue to store indices of values in sorted order
        deque<int> q {0}; 
        for(int i=1; i<nums.size(); i++) {
            if(q.front() < i-k) //stored index not reachable from current index
                q.pop_front();
            
            dp[i] = nums[i] + dp[q.front()]; //update score with the value at front of queue
            
            while(!q.empty() && dp[q.back()] <= dp[i]) //discarded unused indices
                q.pop_back();
            
            q.push_back(i);
        }
        
        return dp.back();
    }
};
//https://leetcode.com/problems/jump-game-vi/