class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int right = piles.size() / 2;
        int left = right-1;
        int pointsAlice = 0, pointsBob = 0;

        while(left >= 0) {
            pointsAlice += max(piles[left], piles[right]);
            pointsBob += min(piles[left], piles[right]);
            left--;
            right++;
        }

        return pointsAlice > pointsBob;
    }
};
//https://leetcode.com/problems/stone-game/