class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int sum = 0, x = *max_element(nums.begin(), nums.end());

        while(k--)
            sum += (x++);

        return sum;
    }
};
//https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/