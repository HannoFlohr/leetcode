class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral (n, vector<int>(n));
        
        vector<vector<int>> directions {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curDirection=0, i=0, j=-1, current=1;
        vector<int> stepsToTake {n, n-1};
        
        while( stepsToTake[curDirection % 2] ) {
            for(int k=0; k<stepsToTake[curDirection%2]; k++) {
                i += directions[curDirection][0];
                j += directions[curDirection][1];
                spiral[i][j] = current++;
            }
            
            stepsToTake[curDirection%2]--;
            curDirection = (curDirection+1) % 4;
        }
        
        return spiral;
    }
};
//https://leetcode.com/problems/spiral-matrix-ii/