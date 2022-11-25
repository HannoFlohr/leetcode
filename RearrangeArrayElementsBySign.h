class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0, negative = 1;
        vector<int> result (nums.size());
        
        for(auto &n : nums) 
            if(n < 0) result[negative] = n, negative += 2;
            else result[positive] = n, positive += 2;
        
        return result;
    }
};
//https://leetcode.com/problems/rearrange-array-elements-by-sign/