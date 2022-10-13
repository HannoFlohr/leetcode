class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX, j=INT_MAX;
        
        for(auto n : nums) {
            if(n <= i) i = n;
            else if(n <= j) j = n;
            else return true;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/increasing-triplet-subsequence/