class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int longest = 2, difference, n = nums.size();
        vector<unordered_map<int,int>> difference_frequency (n);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                difference = nums[i] - nums[j];

                if(difference_frequency[j].count(difference) > 0)
                    difference_frequency[i][difference] = difference_frequency[j][difference]+1;
                else
                    difference_frequency[i][difference] = 2;

                longest = max(longest, difference_frequency[i][difference]);
            }
        }

        return longest;
    }
};
//https://leetcode.com/problems/longest-arithmetic-subsequence/