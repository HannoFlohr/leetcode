class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> numbers (nums.begin(), nums.end());
        return numbers.size() - numbers.count(0); 
    }
};
//https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/