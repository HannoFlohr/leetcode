class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_area = 0, cur_left, cur_right;
		
		//left: index of left boundary of rectangle at current position, 0 = no rectangle
		//right: index of right boundary of rectangle at current position, n = no rectangle
		//height: at current row, number of consecutive '1's in that column including current row
        vector<int> left(n,0), right(n,n), height(n,0);
        
        for(int i=0; i<m; i++) {
            cur_left = 0; cur_right = n;
            
            //update height for current row 
            for(int j=0; j<n; j++) 
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            //update left for current row 
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else left[j] = 0, cur_left = j+1;
            }
            //update right for current row
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else right[j] = n, cur_right = j;
            }

            //update max area of rectangle, check for each column of the current row
            for(int j=0; j<n; j++)
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
        }
        
        return max_area;
    }
};
//https://leetcode.com/problems/maximal-rectangle/