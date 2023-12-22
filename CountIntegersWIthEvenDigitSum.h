class Solution {
public:
    int countEven(int num) {
        int x = num, count = 0;

        while(x > 0) {
            count += x % 10;
            x /= 10;
        }

        return count%2 == 0 ? num/2 : (num-1)/2;
    }
};
//https://leetcode.com/problems/count-integers-with-even-digit-sum/