class Solution {
public:
    long long minEnd(int n, int x) {
        //first valid number is x itself, then find n-1 other valid numbers
        long long number = x;
        while(--n > 0) {
            //increment current number and or with x to get next bigger valid element
            number = (number + 1) | x;
        }
        return number;
    }
};
//https://leetcode.com/problems/minimum-array-end/