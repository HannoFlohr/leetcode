class Solution {

int rows[9][256];
int columns[9][256];
int subgrid[3][3][256];
    
void setCell(int i, int j, char c) {
    rows[i][c] = 1;
    columns[j][c] = 1;
    subgrid[i/3][j/3][c] = 1;
}
    
void unsetCell(int i, int j, char c) {
    rows[i][c] = 0;
    columns[j][c] = 0;
    subgrid[i/3][j/3][c] = 0;
}
    
bool checkCell(int i, int j, char c) {
    if(rows[i][c]==1 || columns[j][c]==1 || subgrid[i/3][j/3][c] == 1)
        return false;
    return true;
}    
    
bool solveGrid(vector<vector<char>>& board, int i, int j) {
    if(i==9) return true;
    if(j==9) return solveGrid(board, i+1, 0);
    if(board[i][j] != '.') return solveGrid(board, i, j+1);
    
    for(char c='1'; c<='9'; c++) {
        if(checkCell(i,j,c)){ 
            board[i][j] = c;
            setCell(i, j, c);
            
            if(solveGrid(board, i, j+1)) 
                return true;
            
            board[i][j] = '.';
            unsetCell(i,j,c);
        }    
    }
    
    return false;
}
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subgrid, 0, sizeof(subgrid));
        
        for(int i=0; i<9; i++) 
            for(int j=0; j<9; j++) 
                if(board[i][j] != '.') {
                    int c = board[i][j];
                    setCell(i, j, c);
                }

        solveGrid(board, 0, 0);
    }
};
//https://leetcode.com/problems/sudoku-solver/