class Solution {

const int MOD = 1e9+7;
    
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers (n);
        for(int i=0; i<n; i++)
            engineers[i] = {efficiency[i], speed[i]};
        sort(engineers.rbegin(), engineers.rend());
        
        long sum = 0, result = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto [e,s] : engineers) {
            q.emplace(s);
            sum += s;
            if(q.size() > k) {
                sum -= q.top();
                q.pop();
            }
            
            result = max(result, sum * e);
        }
        
        return result % MOD;
    }
};
//https://leetcode.com/problems/maximum-performance-of-a-team/