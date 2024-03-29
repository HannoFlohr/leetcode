class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'X') {
                ++moves;
                i += 2;
            }
        }
        return moves;
    }
};
//https://leetcode.com/problems/minimum-moves-to-convert-string/