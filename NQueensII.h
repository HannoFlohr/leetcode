class Solution {
private:
    int n;
    int solutions = 0;
    
    bool valid(vector<string> &board, int row, int col) {
        //check column for other queens
        for(int i=row; i>=0; i--)
            if(board[i][col] == 'Q') 
                return false;
        //check left diagonal for other queens
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 'Q') 
                return false;
        //check right diagonal for other queens
        for(int i=row, j=col; i>=0 && j<n; i--, j++)
            if(board[i][j] == 'Q') 
                return false;
        
        return true;
    }

    void dfs(vector<string> &board, int row) {
        if(row == n) {
            solutions++;
            return;
        }
        
        for(int col=0; col<n; col++) {
            if( valid(board, row, col) ) {
                board[row][col] = 'Q';
                dfs(board, row+1);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int _n) {
        n = _n;
        vector<string> board (n, string(n, '.'));
        dfs(board, 0);
        return solutions;
    }
};
//https://leetcode.com/problems/n-queens-ii/