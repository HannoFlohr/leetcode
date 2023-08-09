class Solution {
public:
    bool check(vector<int>& nums) {
        const int& n = nums.size();

        for(int cur = 0, jump = 0; cur < nums.size(); ++cur) {
            if(nums[cur] > nums[(cur+1)%n]) {
                if(jump == 1)
                    return false;
                else
                    jump = 1;
            }
        }

        return true;
    }
};
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/