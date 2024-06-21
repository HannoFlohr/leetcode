class Solution {
public:
    int specialArray(vector<int>& nums) {
        //count frequency of all numbers
        vector<int> count (1001, 0);
        for(int num : nums) {
            count[num]++;
        }

        //for each x: check if the count of numbers 
        //remaining after x is equal to x
        int remaining = nums.size();
        for(int x = 0; x < 1001; ++x) {
            if(x == remaining) {
                return x;
            }
            remaining -= count[x];
        }

        return -1;
    }
};
//https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/