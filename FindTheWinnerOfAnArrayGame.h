class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur_winner = arr[0], wins = 0;

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > cur_winner) {
                cur_winner = arr[i];
                wins = 0;
            }
            if(++wins == k)
                break;
        }

        return cur_winner;
    }
};
//https://leetcode.com/problems/find-the-winner-of-an-array-game/