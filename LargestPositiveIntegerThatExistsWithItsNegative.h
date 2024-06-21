class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> numbers (nums.begin(), nums.end());

        for(auto it = numbers.rbegin(); it != numbers.rend(); ++it) { 
            if(*it < 0) {
                break;
            }
            if(numbers.contains(-(*it))) {
                return *it;
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/