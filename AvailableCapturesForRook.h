class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int captures = 0, rook_row, rook_col;
        //find rook position
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(board[i][j] == 'R') {
                    rook_row = i;
                    rook_col = j;
                    break;
                }
            }
        }

        //look for capturable pawns
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto [dr,dc] : directions) {
            for(int row = rook_row + dr, col = rook_col + dc; 0 <= row && row < 8 && 0 <= col && col <8; row += dr, col +=dc) {
                if(board[row][col] == 'p') {
                    ++captures;
                }
                if(board[row][col] != '.') {
                    break;
                }
            }
        }

        return captures;
    }
};
//https://leetcode.com/problems/available-captures-for-rook/