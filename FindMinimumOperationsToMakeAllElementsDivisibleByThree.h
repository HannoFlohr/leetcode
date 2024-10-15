class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for(int num : nums) {
            if(num % 3 != 0)
                ++operations;
        }
        return operations;
    }
};
//https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/