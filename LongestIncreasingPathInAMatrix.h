class Solution {
private:
    const vector<pair<int,int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1}};

    int dfs(int x, int y, int m, int n, const vector<vector<int>>& matrix, vector<vector<int>>& lp) {
        if(lp[x][y] != -1) {
            return lp[x][y];
        }

        int x_next, y_next, longest_path = 0;
        for(auto [dx,dy] : directions) {
            x_next = x + dx;
            y_next = y + dy;
            if(x_next < 0 || x_next >= m || y_next < 0 || y_next >= n || matrix[x][y] <= matrix[x_next][y_next]) {
                continue;
            }    

            longest_path = max(longest_path, 1+dfs(x_next, y_next, m, n, matrix, lp));
        }

        return lp[x][y] = longest_path;
    }

public:
    int longestIncreasingPath(const vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> lp (m, vector<int>(n, -1));

        int longest_path = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(i, j, m, n, matrix, lp);
                longest_path = max(longest_path, lp[i][j]);
            }
        }
        
        return longest_path+1;
    }
};
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/