class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        //first three to count rows, than 3 to count columns and last 2 for diagonals
        vector<int> player1 (8,0), player2 (8,0);
        int row, col;

        for(int i=0; i<moves.size(); i++){
            row = moves[i][0], col = moves[i][1];

            vector<int>& player = i%2 == 0 ? player1 : player2;
            player[row]++;
            player[col+3]++;
            if(row==col) player[6]++;
            if(row==2-col) player[7]++;
        }

        for(int i=0; i<8; i++) {
            if(player1[i]==3) return "A";
            if(player2[i]==3) return "B";
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
//https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/