class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        
        for(int i=0; i<nums.size(); i++) {
            auto find = hash.find(target - nums[i]);
            
            if(find != hash.end())
                return vector<int> {i, find->second}; 
            
            hash[nums[i]] = i;
        }
    
        return vector<int> {};
    }
};
//https://leetcode.com/problems/two-sum/