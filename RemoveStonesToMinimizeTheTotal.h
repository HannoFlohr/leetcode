class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q (piles.begin(), piles.end());
        int cur;

        while(!q.empty() && k > 0) {
            cur = q.top() -  (q.top() / 2);
            q.pop();
            q.push(cur);
            k--;
        }

        cur = 0;
        while(!q.empty()) {
            cur += q.top();
            q.pop();
        }

        return cur;
    }
};
//https://leetcode.com/problems/remove-stones-to-minimize-the-total/