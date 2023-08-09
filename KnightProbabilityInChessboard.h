class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if(k == 0)
            return 1.0;

        const vector<int> move_row = {-2,-2,-1,-1,2,2,1,1};
        const vector<int> move_col = {1,-1,2,-2,1,-1,2,-2};
        int dx, dy;
        double probability;

        vector<vector<double>> probabilities (n, vector<double>(n, 0.0));
        vector<vector<double>> nextProbabilites (n, vector<double>(n, 0.0));
        probabilities[row][column] = 1.0;

        for(int step = 0; step < k; ++step) {
            for(int x = 0; x < n; ++x) {
                for(int y = 0; y < n; ++y) {
                    probability = probabilities[x][y] / 8.0;

                    if(probability == 0.0)
                        continue;

                    for(int d = 0; d < 8; ++d) {
                        dx = x + move_row[d];
                        dy = y + move_col[d];

                        if(dx >= 0 && dx < n && dy >= 0 && dy < n) 
                            nextProbabilites[dx][dy] += probability;
                    }
                }
            }

            probabilities = nextProbabilites;
            nextProbabilites = vector<vector<double>> (n, vector<double>(n, 0.0));
        }

        double final_probability = 0.0;
        for(const auto& row : probabilities)
            for(const auto& col : row) 
                final_probability += col;

        return final_probability;
    }
};
//https://leetcode.com/problems/knight-probability-in-chessboard/