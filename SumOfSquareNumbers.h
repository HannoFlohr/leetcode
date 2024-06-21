class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int left = 0, right = sqrt(c), sum;
        while(left <= right) {
            sum = left*left+right*right;
            if(sum == c) {
                return true;
            }
            else if(sum > c) {
                --right;
            }
            else {
                ++left;
            }
        }
        return false;
    }
};
//https://leetcode.com/problems/sum-of-square-numbers/