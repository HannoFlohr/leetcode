class Solution {
private:
    void mark(vector<vector<int>>& land, int x, int xend, int ystart, int yend) {
        for( ; x <= xend; ++x) {
            for(int y = ystart ; y <= yend; ++y) { 
                land[x][y] = 2;
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> farmlands;

        for(int x = 0; x < m; ++x) {
            for(int y = 0; y < n; ++y) {
                if(land[x][y] != 1) {
                    continue;
                }

                //find longest possible rectangle vertically and horizontally
                int xend = x, yend = y; 
                while(xend < m && land[xend][y] == 1) {
                    ++xend;
                }
                while(yend < n && land[x][yend] == 1) {
                    ++yend;
                }
                if(xend != 0) {
                    --xend;
                }
                if(yend != 0) {
                    --yend;
                }

                mark(land, x, xend, y, yend);
                farmlands.push_back({x, y, xend, yend});
            }
        }

        return farmlands;
    }
};
//https://leetcode.com/problems/find-all-groups-of-farmland/