class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long min_replacements = 0, previous = nums[n-1];

        for(int i = n-2; i >= 0; --i) {
            int multiples = nums[i] / previous;

            if(nums[i] % previous != 0) {
                ++multiples;
                previous = nums[i] / multiples;
            }

            min_replacements += multiples-1;
        }

        return min_replacements;
    }
};
//https://leetcode.com/problems/minimum-replacements-to-sort-the-array/