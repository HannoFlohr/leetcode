class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size(), rocks = 0, fill_index;
        vector<vector<char>> rotated (n, vector<char>(m,'.'));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(box[i][j] == '*') {
                    rotated[j][m-1-i] = '*';
                    fill_index = j-1;
                    while(rocks > 0) {
                        rotated[fill_index][m-1-i] = '#';
                        --rocks;
                        --fill_index;
                    }
                }
                if(box[i][j] == '#')
                    ++rocks;
            }

            fill_index = n-1;
            while(rocks > 0) {
                rotated[fill_index][m-1-i] = '#';
                --rocks;
                --fill_index;
            }
        }

        return rotated;
    }
};
//https://leetcode.com/problems/rotating-the-box/