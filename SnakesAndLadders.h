class Solution {
private:
    vector<pair<int,int>> initCells(const int& n) {
        vector<pair<int,int>> cells (n*n+1);

        vector<int> column_index (n);
        iota(column_index.begin(), column_index.end(), 0);

        int cell_number = 1;

        for(int row = n-1; row >= 0; row--) {
            for(const int& column : column_index) 
                cells[cell_number++] = {row, column};
            
            reverse(column_index.begin(), column_index.end());
        }

        return cells;
    }


public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();
        vector<pair<int,int>> cells = initCells(n);
        
        vector<int> distance_from_start (n*n+1, -1);
        queue<int> q;
        int position, move_to;
        distance_from_start[1] = 0;
        q.push(1);

        while(!q.empty()) {
            position = q.front();
            q.pop();

            for(int next = position+1; next <= min(position+6, n*n); next++) {
                auto [row, column] = cells[next];
                move_to = board[row][column] != -1 ? board[row][column] : next;

                if(distance_from_start[move_to] == -1) {
                    distance_from_start[move_to] = distance_from_start[position] + 1;
                    q.push(move_to); 
                }
            }
        }

        return distance_from_start[n*n];
    }
};
//https://leetcode.com/problems/snakes-and-ladders/