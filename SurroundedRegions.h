class Solution {
private: 
    int m, n;
    vector<vector<int>> adjacent {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != 'O') return;

        board[i][j] = 'C';

        for(auto &adj : adjacent)
            dfs(board, i + adj[0], j + adj[1]);
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        //check column borders
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        //check row borders
        for(int i=0; i<n; i++) {
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[m-1][i] == 'O')
                dfs(board, m-1, i);
        }

        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'C') board[i][j] = 'O';
            }
    }
};
//https://leetcode.com/problems/surrounded-regions/

/*
dfs search from row & column borders which 'O's can be reached from 'O's at the boarder and mark those 
afterwards capture unmarked '0's and reset the marked to 'O'  
*/