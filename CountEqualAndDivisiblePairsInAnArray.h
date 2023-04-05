class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> valueToIndices;
        int count = 0;

        for(size_t i=0; i<nums.size(); i++) {
            if(valueToIndices.find(nums[i]) != valueToIndices.end())
                for(const auto& j : valueToIndices[nums[i]])
                    if((i * j) % k == 0)
                        count++;

            valueToIndices[nums[i]].push_back(i);
        }

        return count;
    }
};
//https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/