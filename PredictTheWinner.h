class Solution {
private:
    int dfs(const vector<int>& nums, int left, int right, bool player1turn, vector<vector<vector<long>>>& dp) {
        if(left == nums.size() || right == -1 || left > right)
            return 0;
        if(dp[left][right][player1turn] != INT_MIN)
            return dp[left][right][player1turn];

        if(player1turn) 
            return dp[left][right][player1turn] = max(nums[left] + dfs(nums, left+1, right, false, dp),
                                                      nums[right]+ dfs(nums, left, right-1, false, dp));
        else 
            return dp[left][right][player1turn] = min(-nums[left] + dfs(nums, left+1, right, true, dp),
                                                      -nums[right]+ dfs(nums, left, right-1, true, dp));
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        const int& n = nums.size();
        vector<vector<vector<long>>> dp (n, vector<vector<long>>(n, vector<long>(2, INT_MIN)));
        return dfs(nums, 0, n-1, true, dp) >= 0;
    }
};
//https://leetcode.com/problems/predict-the-winner/