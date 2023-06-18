class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(const auto &n : nums) 
            freq[n]++;

        priority_queue<pair<int,int>> q; 
        for(auto it = freq.begin(); it != freq.end(); it++) 
            q.push(make_pair(it->second, it->first));

        vector<int> result;
        while(k--) {
            result.push_back(q.top().second);
            q.pop();
        }
        
        return result;
    }
};
//https://leetcode.com/problems/top-k-frequent-elements/