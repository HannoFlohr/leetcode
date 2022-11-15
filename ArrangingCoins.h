class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(1 + 8L*n) - 1) / 2;
    }
};
//https://leetcode.com/problems/arranging-coins/

/*
find sum of numbers 1..k = k(k+1) / 2 >= n
-> k^2 + k - 2n >= 0 e.g. a quadratic equation
..
k = sqrt(1 + 8n) - 1 / 2
*/