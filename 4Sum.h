class Solution {
vector<vector<int>> result;
    
void dfs(vector<int>& nums, long target, int left, int right, int k, vector<int>& v) {
    if(target < INT_MIN || target > INT_MAX) return;
    
    if(k==2) {
        while(left < right) {
            if(nums[left] + nums[right] == target) {
                v.push_back(nums[left]);
                v.push_back(nums[right]);
                result.push_back(v);
                v.pop_back();
                v.pop_back();
                
                while(left+1 < right && nums[left]==nums[left+1]) left++;
                left++;
                right--;
            }
            else if(nums[left] + nums[right] > target)
                right--;
            else
                left++;
        }
    }
    
    while(left < right) {
        v.push_back(nums[left]);
        dfs(nums, target-nums[left], left+1, right, k-1, v);
        v.pop_back();
        while(left+1 < right && nums[left]==nums[left+1]) left++;
        left++;
    }
}

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> v;
        dfs(nums, target, 0, nums.size()-1, 4, v);
        
        return result;
    }
};
//https://leetcode.com/problems/4sum/