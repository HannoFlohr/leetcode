class Solution {
private:
    int lessOrEqual(vector<vector<int>>& matrix, int limit) {
        int count = 0;
        for(int row = 0, col = matrix[0].size()-1; row < matrix.size(); ++row) {
            while(col >= 0 && matrix[row][col] > limit) {
                --col;
            }
            count += col+1;
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back(), mid, smallest = -1;

        while(left <= right) {
            mid = (left + right) / 2;
            if(lessOrEqual(matrix, mid) >= k) {
                smallest = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return smallest;
    }
};
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/* straightforward solution using a priority queue as a maxheap; passes all TC

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for(int row = 0; row < matrix.size(); ++row) {
            for(int col = 0; col < matrix[0].size(); ++col) {
                q.push(matrix[row][col]);
                if(q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};
*/