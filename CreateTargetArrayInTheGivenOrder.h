class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;

        for(int i=0; i<nums.size(); ++i) {
            if(i == index[i]) 
                target.push_back(nums[i]);
            else
                target.insert(target.begin()+index[i], nums[i]);
        }

        return target;
    }
};
//https://leetcode.com/problems/create-target-array-in-the-given-order/