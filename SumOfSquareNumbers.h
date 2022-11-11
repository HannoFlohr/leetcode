class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c), sum; 
        
        while(a <= b) {
            sum = a * a + b * b;
            
            if(sum < c) a++;
            else if(sum > c) b--;
            else return true;
        }
        
        return false;
    }
};
//https://leetcode.com/problems/sum-of-square-numbers/