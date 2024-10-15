class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>> visited {{r, c}};
        
        int x = 0, y = 1, temp; 
        for(int steps = 0; visited.size() < rows*cols; ++steps) {
            for(int i = 0; i < steps/2+1; ++i) {
                r += x;
                c += y;
                if(0 <= r && r < rows && 0 <= c && c < cols) {
                    visited.push_back({r, c});
                }
            }
            temp = x;
            x = y;
            y = -temp;
        }
        
        return visited;
    }
};
//https://leetcode.com/problems/spiral-matrix-iii/

/*
pattern: 
right 1 step - down 1 step - left 2 steps - up 2 steps
right 3 step - down 3 step - left 4 steps - up 4 steps
...

check boundaries and loop until sufficient elements were visited
*/