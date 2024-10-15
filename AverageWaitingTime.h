class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait_time = 0.0, cur_time = 0.0;

        for(vector<int>& customer : customers) {
            cur_time = max(cur_time, 1.0 * customer[0]) + customer[1];
            wait_time += cur_time - customer[0];
        }

        return wait_time / customers.size();
    }
};
//https://leetcode.com/problems/average-waiting-time/