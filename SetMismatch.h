class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> contains (nums.size()+1, false);
        int copied=0;
        
        for(int i=0; i<nums.size(); i++) 
            contains[nums[i]] ? (copied = nums[i]) : (contains[nums[i]] = true);
        
        for(int i=1; i<=contains.size(); i++)
            if(contains[i] == false)
                return vector<int>{copied, i};
        
        return {};
    }
};
//https://leetcode.com/problems/set-mismatch/