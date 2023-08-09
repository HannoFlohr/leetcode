class Solution {
private:
    const vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int matToHash(const vector<vector<int>>& mat) {
        int result = 0, factor = 1;
        for(const auto& row : mat) {
            for(int cell : row) {
                result += cell * factor;
                factor *= 2;
            }
        }
        return result;
    }

    vector<vector<int>> hashToMat(int hash, int m, int n) {
        vector<vector<int>> mat (m, vector<int>(n,0));
        int factor = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] = (hash / factor) % 2;
                factor *= 2;
            }
        }
        return mat;
    }

    bool isZeroMatrix(const vector<vector<int>>& mat) {
        for(const auto& row : mat) 
            for(int cell : row) 
                if(cell != 0) 
                    return false;
        return true;
    }

    void flip(vector<vector<int>>& mat, int r, int c, int m, int n) {
        mat[r][c] = 1 - mat[r][c];
        for(const auto& [dr,dc] : directions) {
            int next_r = r+dr, next_c = c+dc;
            if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n) 
                mat[next_r][next_c] = 1 - mat[next_r][next_c];
        }
    }

public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int startState = matToHash(mat);

        queue<int> q;
        q.push(startState);
        unordered_set<int> visited;
        visited.insert(startState);
        int steps = 0;
        
        while(!q.empty()) {
            int qsize = q.size(); 

            while(qsize--) {
                int state = q.front();
                q.pop();

                vector<vector<int>> curMat = hashToMat(state, m, n);

                if(isZeroMatrix(curMat))
                    return steps;

                //try flipping each cell and its neighbors
                for(int i = 0; i < m; ++i) {
                    for(int j = 0; j < n; ++j) {
                        vector<vector<int>> nextMat = curMat;
                        flip(nextMat, i, j, m, n);
                        int nextState = matToHash(nextMat);

                        if(visited.find(nextState) == visited.end()) {
                            visited.insert(nextState);
                            q.push(nextState);
                        }
                    }
                }
            }

            ++steps;
        }

        return -1;
    }
};
//https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/