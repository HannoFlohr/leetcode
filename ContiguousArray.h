class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_length = 0, sum = 0;
        unordered_map<int,int> memo {{0, -1}};

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if(memo.find(sum) != memo.end()) {
                max_length = max(max_length, i - memo[sum]);
            }
            else {
                memo[sum] = i;
            }
        }

        return max_length;
    }
};
//https://leetcode.com/problems/contiguous-array/