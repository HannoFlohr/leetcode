class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long check = 1; 
        int i = 0, patches = 0;

        while(check <= n) {
            if(i < nums.size() && nums[i] <= check) {
                check += nums[i++];
            }
            else {
                check += check;
                ++patches;
            }
        }

        return patches;
    }
};
//https://leetcode.com/problems/patching-array/