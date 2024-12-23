class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> piles;
        for(int gift : gifts) 
            piles.push(gift);

        while(k-- > 0) {
            int pile = sqrt(piles.top());
            piles.pop();
            piles.push(pile);
        }

        long long sum = 0;
        while(!piles.empty()) {
            sum += piles.top();
            piles.pop();
        }
        return sum;
    }
};
//https://leetcode.com/problems/take-gifts-from-the-richest-pile/