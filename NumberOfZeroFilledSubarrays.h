class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int count = 0, zerosEndingAtCurrentPosition = 0;

        for(auto &num : nums) {
            if(num == 0)
                count += ++zerosEndingAtCurrentPosition;
            else
                zerosEndingAtCurrentPosition = 0;
        }

        return count;
    }
};
//https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/919700632/