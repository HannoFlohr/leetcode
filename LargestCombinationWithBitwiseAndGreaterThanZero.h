class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitcount (24, 0);

        for(int candidate : candidates) {
            bitset<24> bits (candidate);
            for(int i = 0; i < 24; ++i) {
                if(bits[i] == 1)
                    ++bitcount[i];
            }
        }

        return *max_element(bitcount.begin(), bitcount.end());
    }
};
//https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/