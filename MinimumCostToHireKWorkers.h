class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size();

        //compute the wage per quality for each worker and sort it
        vector<pair<double,int>> wage_per_quality (n);
        for(int i = 0; i < n; ++i) {
            wage_per_quality[i] = {static_cast<double>(wage[i]) / quality[i] , i};
        }
        sort(wage_per_quality.begin(), wage_per_quality.end());

        //priority queue for tracking the highest quality workers 
        priority_queue<int> q;
        int quality_sum = 0;
        double max_rate = 0.0;
        //add first k workers to the priority queue to get an initial cost
        for(int i = 0; i < k; ++i) {
            quality_sum += quality[wage_per_quality[i].second];
            max_rate = max(max_rate, wage_per_quality[i].first);
            q.push(quality[wage_per_quality[i].second]);
        }

        double min_cost = max_rate * quality_sum;
        //remaining workers: check if firing the lowest quality worker in the priority queue
        //and hiring another one gives a better minimum overall cost
        for(int i = k; i < n; ++i) {
            //update max_rate for new worker
            max_rate = max(max_rate, wage_per_quality[i].first);
            //remove old worker from and add new worker to quality sum
            quality_sum -= q.top();
            q.pop();
            quality_sum += quality[wage_per_quality[i].second];
            q.push(quality[wage_per_quality[i].second]);
            //update min cost with swapped workers
            min_cost = min(min_cost, max_rate * quality_sum);
        }

        return min_cost;
    }
};
//https://leetcode.com/problems/minimum-cost-to-hire-k-workers/