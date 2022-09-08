class Solution {

int m, n;
vector<vector<int>> result;    
vector<vector<bool>> pacific, atlantic;
    
void bfs(vector<vector<int>> heights, vector<vector<bool>>& visited, int i, int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()) {
        tie(i,j) = q.front(); 
        q.pop();
        if(visited[i][j])
            continue;
        
        visited[i][j] = true;
        if(pacific[i][j] && atlantic[i][j]) 
            result.push_back(vector<int>{i,j});
        
        if(i+1 <  m && heights[i+1][j] >= heights[i][j]) q.push({i+1, j});
        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j]) q.push({i-1, j});
        if(j+1 <  n && heights[i][j+1] >= heights[i][j]) q.push({i, j+1});
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j]) q.push({i, j-1});
    }
}
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); 
        n = heights[0].size();   
        pacific = vector<vector<bool>> (m, vector<bool>(n, false));
        atlantic = pacific;
        
        for(int i=0; i<m; i++) {
            bfs(heights, pacific, i, 0);
            bfs(heights, atlantic, i, n-1);
        }
        for(int i=0; i<n; i++) {
            bfs(heights, pacific, 0, i);
            bfs(heights, atlantic, m-1, i);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/pacific-atlantic-water-flow/