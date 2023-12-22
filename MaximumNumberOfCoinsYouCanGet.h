class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i = piles.size()-2, bob = 0, sum = 0;

        while (i > bob) {
            sum += piles[i];
            i -= 2;
            bob++;
        }

        return sum;
    }
};
//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/