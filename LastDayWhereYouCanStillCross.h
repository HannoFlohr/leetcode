class Solution {
private:
    bool canReachEnd(const vector<vector<int>>& cells, int rows, int cols, int mid) {
        const vector<pair<int,int>> directions {{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<bool>> grid (rows+1, vector<bool>(cols+1, 0));
        for(int i = 0; i < mid; ++i)
            grid[cells[i][0]][cells[i][1]] = 1;

        queue<pair<int,int>> q;
        for(int c = 1; c <= cols; ++c) {
            if(grid[1][c] == 0) {
                q.push({1,c});
                grid[1][c] = 1;
            }
        }

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(const auto& [dx,dy] : directions) {
                int to_x = x+dx, to_y = y+dy;
                if(to_x <= 0 || to_x > rows || to_y <= 0 || to_y > cols || grid[to_x][to_y] == 1)
                    continue;
                if(to_x == rows)
                    return true;

                grid[to_x][to_y] = 1;
                q.push({to_x,to_y});
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row*col, mid, latest_day = 0;

        while(left < right-1) {
            mid = left + (right - left) / 2;
            if(canReachEnd(cells, row, col, mid)) {
                left = mid;
                latest_day = mid;
            }
            else
                right = mid;
        }

        return latest_day;
    }
};
//https://leetcode.com/problems/last-day-where-you-can-still-cross/