class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 ? true : num % 10 != 0;
    }
};
//https://leetcode.com/problems/a-number-after-a-double-reversal/