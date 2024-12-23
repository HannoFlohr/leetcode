class Solution {
private:
    double profit(const double& pass, const double& total) {
        return (pass+1)/(total+1) - pass/total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double total = 0;
        priority_queue<pair<double,pair<int,int>>> q;

        for(vector<int>& c : classes) {
            total += (double)c[0] / c[1];
            q.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        while(extraStudents--) {
            auto [add_profit, c] = q.top();
            q.pop();
            total += add_profit;
            q.push({profit(c.first+1, c.second+1), {c.first+1, c.second+1}});
        }

        return total / classes.size();
    }
};
//https://leetcode.com/problems/maximum-average-pass-ratio/