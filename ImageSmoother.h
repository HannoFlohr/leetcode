class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        const int m = img.size(), n = img[0].size();
        vector<vector<int>> smoothed (m, vector<int>(n,0));

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                int sum = img[row][col], neighbors = 1;
                for(auto& [dx,dy] : directions) {
                    if(row+dx >= 0 && row+dx < m && col+dy >= 0 && col+dy < n) {
                        sum += img[row+dx][col+dy];
                        ++neighbors;
                    }
                }
                smoothed[row][col] = sum/neighbors;
            }
        }

        return smoothed;
    }
};
//https://leetcode.com/problems/image-smoother/