class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> frequency;
        for(int n : nums)
            frequency[n]++;

        int count = 0, operations = 0;
        for(auto it = frequency.rbegin(); it != frequency.rend(); it++) {
            count += it->second;
            operations += count - it->second;
        }

        return operations;
    }
};
//https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/