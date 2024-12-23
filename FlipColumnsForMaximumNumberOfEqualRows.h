class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int rowsize = matrix[0].size();
        unordered_map<string, int> patterns;

        for(vector<int>& row : matrix) {
            //create pattern for current row
            string pattern (rowsize, 't');
            for(int i = 1; i < rowsize; ++i) {
                if(row[i] != row[0])
                    pattern[i] = 'f';
            }
            //increment count for that pattern
            ++patterns[pattern];
        }

        int max_count = 0;
        for(auto& pattern : patterns)
            max_count = max(max_count, pattern.second);
        return max_count;
    }
};
//https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/