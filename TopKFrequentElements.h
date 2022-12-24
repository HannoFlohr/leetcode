class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &n : nums) 
            freq[n]++;

        priority_queue<pair<int,int>> q; 
        vector<int> result;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            q.push(make_pair(it->second, it->first));
            if(q.size() > freq.size() - k) {
                result.push_back(q.top().second);
                q.pop();
            }
        }
        
        return result;
    }
};
//https://leetcode.com/problems/top-k-frequent-elements/