class Solution {
private:
    int m, n;
    string _word;
    vector<vector<bool>> visited;
    
    bool inBounds(int &i, int &j) {
        return i>=0 && i<m && j>=0 && j<n;
    } 
    
    bool find(vector<vector<char>>& board, int i, int j, int pos) { 
        //check if in bounds and if already visited
        if(!inBounds(i,j) || visited[i][j]) return false;
        //check if the letter in the word matches the letter on the board
        if(board[i][j] != _word[pos]) return false;
        //found the last letter of the word, return true
        if(pos == _word.size()-1) return true;
        
        //mark cell as visited
        visited[i][j] = true;
        
        //search in all four possible directions
        if( find(board, i-1, j, pos+1) || find(board, i+1, j, pos+1) || find(board, i, j-1, pos+1) || find(board, i, j+1, pos+1) )
            return true;
        
        //backtrack marking of cell to not visited
        visited[i][j] = false;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        _word = word;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if( find(board, i, j, 0) )
                    return true;
        return false;
    }
};
//https://leetcode.com/problems/word-search/