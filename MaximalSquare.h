class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_square = 0;
        //check if at least one '1' is present -> minimal max_square of size 1
        for(auto &r:matrix) {
            for(auto &c:r) 
                if(c == '1') { 
                    max_square = 1;
                    break;
                }
            
            if(max_square == 1)
                break;
        }
        
		//dp[i][j] contains the side length of the maximum square at row i, column j 
        vector<vector<int>> dp(m, vector<int>(n,0));
		//max square side length at boundaries equals the value at boundaries in matrix
        for(int i=0; i<m; i++) dp[i][0] = matrix[i][0]-'0';
        for(int j=0; j<n; j++) dp[0][j] = matrix[0][j]-'0';
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == '0') continue; 
                //we can have a square with side length 1 at least
                dp[i][j] = 1;
                //if the three adjacent cells left and above aren't 0, we found a longer side length 
                if(dp[i-1][j-1] > 0 && dp[i-1][j] > 0 && dp[i][j-1] > 0) {
                    dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                
                    max_square = max(max_square, dp[i][j]);
                }
            }
        }
        
        
        return max_square * max_square;
    }
};
//https://leetcode.com/problems/maximal-square/