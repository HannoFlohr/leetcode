class Solution {

public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != 'X')
                    continue;
                if((i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X'))       
                    ++count;
            }
        }

        return count;
    }
};

//https://leetcode.com/problems/battleships-in-a-board/

/* first approach: marking the ships

class Solution {
private:
    void markShip(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return;

        if(board[x][y] != 'X') {
            board[x][y] = 'O';
            return;    
        }

        board[x][y] = 'O';
        markShip(board, x+1, y);
        markShip(board, x, y+1);
    }

    bool findNewShip(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] != 'X')
            return false;

        markShip(board, x, y);
        return true;
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j) 
                if(findNewShip(board, i, j))
                    ++count;

        return count;
    }
};
*/