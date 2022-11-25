class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_consecutive = 0, cur = 0;
        for(auto &n : nums)
            if(n==1) max_consecutive = max(max_consecutive, ++cur);
            else cur = 0;
        
        return max_consecutive;    
    }
};
//https://leetcode.com/problems/max-consecutive-ones/