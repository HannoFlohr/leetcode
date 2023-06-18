using ll = long long;

class Solution {
private:
    const int MOD = 1e9+7;

    ll dfs(const vector<int>& nums, vector<vector<ll>>& table) {
        if(nums.size() <= 2)
            return 1;

        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll left_result = dfs(left, table) % MOD;
        ll right_result = dfs(right, table) % MOD;

        return (((table[nums.size()-1][left.size()] * left_result) % MOD) * right_result) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        vector<vector<ll>> table (nums.size()+1);

        for(int i = 0; i < nums.size(); ++i) {
            table[i] = vector<ll>(i+1, 1);

            for(int j = 1; j < i; ++j)
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MOD;
        }

        return dfs(nums, table) % MOD - 1;
    }
};
//https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/