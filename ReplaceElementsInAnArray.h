class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> position;
        for(int i = 0; i < nums.size(); ++i) 
            position[nums[i]] = i;
        
        for(vector<int>& op : operations) {
            nums[position[op[0]]] = op[1];
            position[op[1]] = position[op[0]];
        }

        return nums;
    }
};
//https://leetcode.com/problems/replace-elements-in-an-array/