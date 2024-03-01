class Solution {
private:
    void checkSums(const vector<int>& sums, int target, int& count) {
        unordered_map<int,int> sum_freq;
        int sum = 0;
        sum_freq[0]++;
        for(int i : sums) {
            sum += i;
            count += sum_freq[sum-target];
            sum_freq[sum]++;
        }
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int count = 0;

        
        //loop through all rows as starter row
        for(int row_start = 0; row_start < m; ++row_start) {
            vector<int> row (n, 0);

            //for each starter row, sum up the rows from start row to the end consecutively
            for(int row_end = row_start; row_end < m; ++row_end) {
                for(int col = 0; col < n; ++col) {
                    row[col] += matrix[row_end][col];
                }
                //count sums that equal target sum
                checkSums(row, target, count);
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/