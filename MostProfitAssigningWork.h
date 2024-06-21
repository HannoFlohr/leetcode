class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for(int i = 0; i < profit.size(); ++i) {
            jobs.push_back({profit[i], difficulty[i]});
        }
        sort(jobs.rbegin(), jobs.rend());
        
        sort(worker.rbegin(), worker.rend());

        int max_profit = 0, job = 0;
        for(int w : worker) {
            while(job < jobs.size() && jobs[job].second > w) {
                ++job;
            }
            if(job == jobs.size()) {
                break;
            }
            max_profit += jobs[job].first;
        }

        return max_profit;
    }
};
//https://leetcode.com/problems/most-profit-assigning-work/