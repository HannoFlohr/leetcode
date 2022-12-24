class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int quadruplets = 0, n = nums.size();
        unordered_map<int,int> difference;
        difference[nums[n-1] - nums[n-2]]++;

        for(int b = n-3; b >= 1; b--) {
            for(int a = b-1; a >= 0; a--)
                quadruplets += difference[nums[a] + nums[b]];

            for(int i = n-1; i > b; i--)
                difference[nums[i] - nums[b]]++;
        }

        return quadruplets;
    }
};
//https://leetcode.com/problems/count-special-quadruplets/