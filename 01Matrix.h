class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        const vector<pair<int,int>> directions {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<vector<int>> distances (m, vector<int>(n, 1e5));
        queue<pair<int,int>> q;
        int qsize, current_distance = 0;

        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j) 
                if(mat[i][j] == 0) 
                    q.push({i,j});
                
        while(!q.empty()) {
            qsize = q.size();

            while(qsize--) {
                auto[x,y] = q.front(); 
                q.pop();

                distances[x][y] = min(distances[x][y], current_distance);

                for(const auto& [dx,dy] : directions) {
                    int xmove = x+dx, ymove = y+dy;
                    if(xmove >= 0 && xmove < m && ymove >= 0 && ymove < n && distances[xmove][ymove] == 1e5)
                        q.push({xmove,ymove});
                }
            }

            ++current_distance;
        }

        return distances;
    }
};
//https://leetcode.com/problems/01-matrix/