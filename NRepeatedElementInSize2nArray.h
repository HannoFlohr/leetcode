class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> numbers;
        for(int n : nums) {
            auto result = numbers.insert(n);
            if(result.second == 0) {
                return n;
            }
        }
        return -1;
    }
};
//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/