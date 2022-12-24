class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        unordered_map<int,int> count;
        for(auto &n : nums)
            pairs += count[n]++;
        return pairs;
    }
};
//https://leetcode.com/problems/number-of-good-pairs/