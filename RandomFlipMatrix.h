class Solution {
private:
    unordered_set<int> cells;
    int max_cells, rows, cols;
public:
    Solution(int m, int n) : rows(m), cols(n) {
        max_cells = m * n;
    }
    
    vector<int> flip() {
        if(cells.size() == max_cells) {
            return {};
        }
        
        int random_cell = rand() % max_cells;
        while(cells.find(random_cell) != cells.end()) {
            random_cell = (++random_cell) % max_cells;
        }
        cells.insert(random_cell);

        return {random_cell/cols, random_cell%cols};
    }
    
    void reset() {
        cells = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
//https://leetcode.com/problems/random-flip-matrix/

/* 19/20 testcases passed

class Solution {
private:
    vector<vector<int>> matrix;
    int max_x, max_y;
public:
    Solution(int m, int n) : max_x(m), max_y(n) {
        matrix = vector<vector<int>>(m, vector<int>(n, 0));
    }
    
    vector<int> flip() {
        bool flipped = false;
        int x, y;
        while(!flipped) {
            x = rand() % max_x;
            y = rand() % max_y;
            if(matrix[x][y] == 0) {
                matrix[x][y] = 1;
                flipped = true;
            }
        }
        return {x,y};
    }
    
    void reset() {
        matrix = vector<vector<int>>(max_x, vector<int>(max_y, 0));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
 
 /*