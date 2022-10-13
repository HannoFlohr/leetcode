class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        vector<vector<int>> directions {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curDirection=0, i=0, j=-1;
        vector<int> stepsToTake {(int)matrix[0].size(), (int)matrix.size()-1};
        
        while( stepsToTake[curDirection % 2] ) {
            for(int k=0; k<stepsToTake[curDirection%2]; k++) {
                i += directions[curDirection][0];
                j += directions[curDirection][1];
                result.push_back(matrix[i][j]);
            }
            
            stepsToTake[curDirection%2]--;
            curDirection = (curDirection+1) % 4;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/spiral-matrix

/*
looking at the example we can see that starting from [0][-1]
we move in direction 	RIGHT DOWN LEFT UP
						m 	  n-1  m-1  n-2
						m-2   n-3  m-3  n-4
						...					times
until the steps to take for m or n reaches 0
*/