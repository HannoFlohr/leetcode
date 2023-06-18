class SubrectangleQueries {
private:
    vector<vector<int>> matrix;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; ++i)
            for(int j = col1; j <= col2; ++j)
                matrix[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
 
//https://leetcode.com/problems/subrectangle-queries/
 
class SubrectangleQueries {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> updates;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, row2, col1, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = updates.size()-1; i >= 0; --i)  
            if(updates[i][0] <= row && row <= updates[i][1] && updates[i][2] <= col && col <= updates[i][3])
                return updates[i][4];
        return matrix[row][col];
    }
};