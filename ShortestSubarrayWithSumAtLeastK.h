class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), shortest = INT_MAX;
        deque<int> q;
        vector<long> sums (n);
        for(int i = 0; i < n; ++i)
            sums[i] = (long)nums[i];

        for(int i = 0; i < n; ++i) {
            //compute sum for current subarray
            if(i > 0)
                sums[i] += sums[i-1];
            //update shortest
            if(sums[i] >= k)
                shortest = min(shortest, i+1);
            //shortest subarray starting at the index at front of q with sum >= k ends at current i
            //so that index can be popped from the queue
            while(!q.empty() && sums[i] - sums[q.front()] >= k) {
                shortest = min(shortest, i - q.front());
                q.pop_front();
            }
            //keep q increasing
            while(!q.empty() && sums[i] <= sums[q.back()])
                q.pop_back();

            q.push_back(i);
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
//https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/