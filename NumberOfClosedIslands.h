class Solution {
private:
    bool isClosedIsland(vector<vector<int>>& grid, int x, int y) {
        //check bounds
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())
            return false;
        //cell is water / was visited before -> true
        if(grid[x][y] > 0)
            return true;

        //mark cell as visited
        grid[x][y] = 2;

        //check the for neighboring cells
        bool closed_above = isClosedIsland(grid, x-1, y);
        bool closed_below = isClosedIsland(grid, x+1, y);
        bool closed_left  = isClosedIsland(grid, x, y-1);
        bool closed_right = isClosedIsland(grid, x, y+1);
        //if all four cells are water/belong to same island, a closed island is found
        return closed_above && closed_below && closed_left && closed_right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 0)
                    result += isClosedIsland(grid, i, j);

        return result;
    }
};
//https://leetcode.com/problems/number-of-closed-islands/