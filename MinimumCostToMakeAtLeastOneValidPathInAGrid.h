class Solution {
private:
    const vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(const vector<vector<int>>& grid, int m, int n, int x, int y, int cost, vector<vector<int>>& dp, queue<pair<int,int>>& q) {
        //check if out of bounds or cell reached before
        if(x < 0 || x == m || y < 0 || y == n || dp[x][y] != INT_MAX) {
            return;
        }

        dp[x][y] = cost;
        //put all reachable cells in the queue
        q.push({x,y});
        //continue according to the direction of the current cell
        int direction = grid[x][y] - 1;
        dfs(grid, m, n, x+directions[direction][0], y+directions[direction][1], cost, dp, q);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cost = 0, qsize; 
        vector<vector<int>> dp (m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        //check which cells can be reached starting from origin according to directions of cells
        dfs(grid, m, n, 0, 0, cost, dp, q); 

        /*
            reachable cells are now in the queue
            in each round increase cost (e.g. change of direction of a cell)
            and check which new cells become reachable (and put them in q for next round) (dfs(...))
        */
        while(!q.empty()) {
            cost++;
            qsize = q.size();
            while(qsize-- > 0) {
                pair<int,int> p = q.front();
                q.pop();

                for(const vector<int>& direction : directions) {
                    dfs(grid, m, n, p.first+direction[0], p.second+direction[1], cost, dp, q);
                }
            }
        }

        return dp[m-1][n-1];
    }
};
//https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/