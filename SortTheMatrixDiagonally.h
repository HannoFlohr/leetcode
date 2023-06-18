class Solution {
private:
    int m, n;

	/*
		for digaonal at start mat[row][column]: 
		- gather all values of diagonal
		- sort values
		- write in sorted order to mat 
	*/
	void sortDiagonal(int row, int column, vector<vector<int>>& mat) {
        vector<int> values;

        for(int i = row, j = column; i < m && j < n; ++i, ++j)
            values.push_back(mat[i][j]);

        sort(values.begin(), values.end());

        for(int i = row, j = column, k = 0; i < m && j < n; ++i, ++j, ++k)
            mat[i][j] = values[k];
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();

		//start point for all diagonals
        for(int column = 0; column < n; ++column) 
            sortDiagonal(0, column, mat);
        for(int row = 1; row < m; ++row)
            sortDiagonal(row, 0, mat);

        return mat;
    }
};
//https://leetcode.com/problems/sort-the-matrix-diagonally/

/* another approach using priority queues (tested slower and more memory usage)

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        // map for each diagonal to a priority queue of the values in that diagonal; index i-j for each diagonal 
        map<int, priority_queue<int, vector<int>, greater<int>>> diagonals; 

        //fill priority queues
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j)
                diagonals[i-j].push(mat[i][j]);

        //write sorted values to mat
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = diagonals[i-j].top();
                diagonals[i-j].pop();
            }
        }

        return mat;
    }
};

*/