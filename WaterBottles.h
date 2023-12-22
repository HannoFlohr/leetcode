class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0, full = numBottles, empty = 0;

        while(full > 0) {
            count += full;
            empty += full;
            full = empty / numExchange;
            empty %= numExchange;
        }

        return count;
    }
};
//https://leetcode.com/problems/water-bottles/