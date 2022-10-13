class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++) {
            if(m[ nums[i] ] > 0 && abs(i - (m[ nums[i] ] - 1)) <= k)
                return true;
            m[ nums[i] ] = i + 1;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/contains-duplicate-ii/