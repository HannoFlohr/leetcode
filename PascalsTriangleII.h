class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur_row, last_row; 
        
        for(int i = 0; i <= rowIndex; i++) { 
            cur_row = vector<int> (i+1, 1);
            
            for(int j = 1; j < i; j++) { 
                cur_row[j] = last_row[j-1] + last_row[j];
            }
            last_row = cur_row;
        }
                
        return cur_row;
    }
};
https://leetcode.com/problems/pascals-triangle-ii/