class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[nums.size()-1]);
    }
};
//https://leetcode.com/problems/find-greatest-common-divisor-of-array/