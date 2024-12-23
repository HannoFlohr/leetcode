class Solution {
public:
    vector<bool> isArraySpecial(const vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> count_special_subarrays (1, 0);
        for(int i = 1; i < nums.size(); ++i)
            count_special_subarrays.push_back(count_special_subarrays.back() + (nums[i]%2 == nums[i-1]%2));

        vector<bool> results (queries.size());
        for(int i = 0; i < queries.size(); ++i)
            results[i] = (count_special_subarrays[queries[i][0]] == count_special_subarrays[queries[i][1]]);
            
        return results;
    }
};
//https://leetcode.com/problems/special-array-ii/