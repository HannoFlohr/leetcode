class Solution {
private:
    void dfs(const vector<int>& nums, int start, vector<int>& sequence, vector<vector<int>>& result) {
        if(sequence.size() > 1) result.push_back(sequence);

        unordered_set<int> added_in_this_step;

        for(int i=start; i<nums.size(); i++) {
            if((sequence.empty() || nums[i] >= sequence.back()) && added_in_this_step.find(nums[i]) == added_in_this_step.end()) {
                sequence.push_back(nums[i]);
                dfs(nums, i+1, sequence, result);
                sequence.pop_back();

                added_in_this_step.insert(nums[i]);
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sequence;
        dfs(nums, 0, sequence, result);
        return result;
    }
};
//https://leetcode.com/problems/non-decreasing-subsequences/