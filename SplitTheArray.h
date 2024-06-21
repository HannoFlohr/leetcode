class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> count (101, 0);
        for(int n : nums) {
            if(++count[n] == 3) {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.com/problems/split-the-array/