class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int triplets = 0;

        for(const auto& num : nums) 
            if(find(nums.begin(), nums.end(), num+diff) != nums.end() && find(nums.begin(), nums.end(), num+diff+diff) != nums.end())
                triplets++;

        return triplets;
    }
};
//https://leetcode.com/problems/number-of-arithmetic-triplets/