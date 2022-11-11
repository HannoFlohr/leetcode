class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while(x*x > num)
            x = (x + num / x) / 2;
        return x * x == num;
    }
};
//https://leetcode.com/problems/valid-perfect-square/

//using Heron's method  for finding the square root for large integers:
//https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division