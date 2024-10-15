class Solution {
private:
    const vector<pair<int,int>> directions = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    void reveal(vector<vector<char>>& board, int r, int c) {
        int adjacent_mines = 0, m = board.size(), n = board[0].size();
        //check if adjacent cells contain mines
        for(auto [dr,dc] : directions) {
            int next_r = r+dr, next_c = c+dc;
            if(0 <= next_r && next_r < m && 0 <= next_c && next_c < n && board[next_r][next_c] == 'M')
                ++adjacent_mines;
        }
        //if there are mines adjacent, mark how many and stop reveal
        if(adjacent_mines != 0) {
            board[r][c] = adjacent_mines+'0';
            return;
        }
        //no mines -> reveal adjacent cells
        board[r][c] = 'B';
        for(auto [dr,dc] : directions) {
            int next_r = r+dr, next_c = c+dc;
            if(0 <= next_r && next_r < m && 0 <= next_c && next_c < n && board[next_r][next_c] == 'E')
                reveal(board, next_r, next_c);
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        reveal(board, click[0], click[1]);    
        return board;
    }
};
//https://leetcode.com/problems/minesweeper/