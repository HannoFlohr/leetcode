
//https://leetcode.com/problems/kth-largest-element-in-an-array/

/* O(n log k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq (begin(nums), end(nums));

        while(pq.size() > k) pq.pop();

        return pq.top();
    }
};
*/