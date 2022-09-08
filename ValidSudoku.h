class Solution {
    
short getMinFor3x3(int i){
    if(i < 3) return 0;
    else if(i<6) return 3;
    else return 6;
}
    
bool isValid(vector<vector<char>>& board, int row, int column) {
    char c = board[row][column];
    
    //check row
    for(int i=0; i<9; i++)
        if(i!=column && board[row][i] == c)
            return false;
    
    //check column
    for(int i=0; i<9; i++)
        if(i!=row && board[i][column] == c)
            return false;
    
    //check 3x3 subgrid
    short minrow = getMinFor3x3(row);
    short mincol = getMinFor3x3(column);

    for(short i=minrow; i<=minrow+2; i++) {
        for(short j=mincol; j<=mincol+2; j++) {
            if(j==column && i==row)
                continue;
            if(board[i][j] == c)
                return false;
        }
    }
    
    return true;
}
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) 
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                if(!isValid(board,i,j))
                    return false;
            }
        return true;
    }
};
//https://leetcode.com/problems/valid-sudoku/