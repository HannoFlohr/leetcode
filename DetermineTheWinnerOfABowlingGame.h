class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int points1 = player1[0], points2 = player2[0];

        for(int i = 1; i < player1.size(); i++) {
            if(player1[i-1] == 10 || (i-2 >= 0 && player1[i-2] == 10))
                points1 += player1[i] + player1[i];
            else
                points1 += player1[i];
        
            if(player2[i-1] == 10 || (i-2 >= 0 && player2[i-2] == 10))
                points2 += player2[i] + player2[i];
            else
                points2 += player2[i];
        }

        if(points1 == points2)
            return 0;
        return points1 > points2 ? 1 : 2;
    }
};
//https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/