class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> numbers (nums.begin(), nums.end());

        for(auto it = numbers.rbegin(); *it > 0 && it != numbers.rend(); ++it) {
            if(numbers.contains(-(*it))) {
                return *it;
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/