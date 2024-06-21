class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums (1,0);

        for(vector<int>& row : mat) {
            //calculate new possible sums for current row and sort those
            vector<int> new_sums;
            for(int col : row) {
                for(int sum : sums) {
                    new_sums.push_back(col + sum);
                }
            } 
            sort(new_sums.begin(), new_sums.end());
            
            //update overall sums until limit
            int limit = min(k+1, (int)new_sums.size());
            sums = vector<int>(new_sums.begin(), new_sums.begin()+limit);
        }

        return sums[k-1];
    }
};
//https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

/* brute force, 29/72 testcases passed

class Solution {
private:
    void makeSums(vector<vector<int>>& mat, int r, int sum, priority_queue<int, vector<int>, greater<int>>& q) {
        if(r == mat.size()) {
            q.push(sum);
            return;        
        }
        for(int col : mat[r]) {
            makeSums(mat, r+1, sum+col, q);
        }
    }

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        const int m = mat.size(), n = mat[0].size();
        priority_queue<int, vector<int>, greater<int>> q;
        makeSums(mat, 0, 0, q);

        while(--k > 0) {
            q.pop();
        }
        return q.top();
    }
};

*/