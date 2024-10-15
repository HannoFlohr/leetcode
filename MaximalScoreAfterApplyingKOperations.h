class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> q (nums.begin(), nums.end());

        while(!q.empty() && k-- > 0) {
            int cur = q.top(); 
            q.pop();

            score += cur;

            cur = (cur + 2) / 3;
            q.push(cur);
        }

        return score;
    }
};
//https://leetcode.com/problems/maximal-score-after-applying-k-operations/