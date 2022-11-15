class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //if each cell is a mine-> no plus
        if(mines.size() == n*n) return 0;
        
        //set grid
        vector<vector<int>> grid (n, vector<int>(n, 1));
        for(auto &m : mines)
            grid[m[0]][m[1]] = 0;
        
        int order=0, x, y;

        //create four matrices denoting continuous '1's when searching from left, right, top and bottom of each row/column
        vector<vector<int>> left, right, up, down;
        left = right = up = down = grid;
        for(int i=0; i<n; i++) {
            x = n - i - 1;
            
            for(int j=0; j<n; j++) { 
                y = n - j - 1;
                
                if(j>0     && left[i][j] ) left[i][j]  += left[i][j-1];
                if(y<n-1   && right[x][y]) right[x][y] += right[x][y+1];                    
                if(i>0     && up[i][j]   ) up[i][j]    += up[i-1][j];
                if(x<n-1   && down[x][y] ) down[x][y]  += down[x+1][y];
            }
        }

        //using the four matrices we can find the highest order plus
        //the lowest value for each (i,j) denotes the highest order that can be built at center (i,j)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                order = max(order, min({left[i][j], right[i][j], up[i][j], down[i][j]}) );
        
        return order;
    }
};
//https://leetcode.com/problems/largest-plus-sign/