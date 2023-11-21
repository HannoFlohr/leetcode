class Solution {
public:
    bool winnerOfGame(string colors) {
        int moves_a = 0, moves_b = 0;

        for(int i = 1; i < colors.size()-1; i++) {
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') {
                    moves_a++;
                }
                else {
                    moves_b++;
                }
            }
        }
        

        return moves_a > moves_b;
    }
};
//https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

/*
class Solution {
public:
    bool winnerOfGame(string colors) {
        int consecutive = 1, moves_a = 0, moves_b = 0;

        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[i-1]) {
                consecutive++;
                if(i < colors.size()-1){
                    continue;
                }
            }

            if(consecutive > 2) {
                if(colors[i-1] == 'A') {
                    moves_a += consecutive - 2;
                }
                else {
                    moves_b += consecutive - 2;
                }
            }

            consecutive = 1;
        }

        return moves_a > moves_b;
    }
};
*/