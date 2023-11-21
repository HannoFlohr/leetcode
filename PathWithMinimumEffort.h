class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const vector<pair<int,int>> directions {{-1,0},{1,0},{0,-1},{0,1}};
        const int rows = heights.size(), cols = heights[0].size();
    
        vector<vector<int>> effort (rows, vector<int>(cols,INT_MAX));
        //first: effort, second: x*100+y
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});

        while(!q.empty()) {
            int cur_effort = q.top().first;
            int x = q.top().second/100, y = q.top().second%100;
            q.pop();

            if(x == rows-1 && y == cols-1) {
                return cur_effort;
            }
            if(cur_effort >= effort[x][y]) {
                continue;
            }
            effort[x][y] = cur_effort;

            for(auto [dx,dy] : directions) {
                int x_next = x+dx, y_next = y+dy;
                if(x_next >= 0 && x_next < rows && y_next >= 0 && y_next < cols) {
                    int effort_next = max(cur_effort, abs(heights[x][y]-heights[x_next][y_next])); 
                    q.push({effort_next, x_next*100+y_next});
                }
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/path-with-minimum-effort/