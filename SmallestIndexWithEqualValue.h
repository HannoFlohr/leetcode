class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(size_t i=0; i<nums.size(); i++) 
            if(i % 10 == nums[i])
                return i;

        return -1;
    }
};
//https://leetcode.com/problems/smallest-index-with-equal-value/