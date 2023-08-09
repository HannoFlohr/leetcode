class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> q_front;
        priority_queue<int, vector<int>, greater<int>> q_back;
        int front = 0, back = costs.size()-1, low_front, low_back;
        long long result = 0;
        
        while(k-- > 0) {
            while(q_front.size() < candidates && front <= back)
                q_front.push(costs[front++]);
            while(q_back.size() < candidates && front <= back)
                q_back.push(costs[back--]);

            low_front = q_front.size() ? q_front.top() : INT_MAX;
            low_back = q_back.size() ? q_back.top() : INT_MAX;

            if(low_front <= low_back) {
                result += low_front;
                q_front.pop();
            }
            else {
                result += low_back;
                q_back.pop();
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/total-cost-to-hire-k-workers/