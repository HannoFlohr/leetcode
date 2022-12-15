class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return (left == right) ? left : rangeBitwiseAnd(left/2, right/2) * 2; 
    }
};
//https://leetcode.com/problems/bitwise-and-of-numbers-range/

/*
start at lowest bit, if left is smaller than right the AND of all numbers between left and right at the last bit will always be 0
than recursively look at the next bit by shifting left and right until left == right 
*/