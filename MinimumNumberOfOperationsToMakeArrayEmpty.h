class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        unordered_map<int,int> frequency;

        for(int n : nums) {
            frequency[n]++;
        }

        for(auto [_,f] : frequency) {
            if(f == 1)
                return -1;

            operations += f/3;
            if(f%3 != 0)
                operations++;
        }

        return operations;
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/