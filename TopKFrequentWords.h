class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //set frequencies of words 
		unordered_map<string,int> freq;
        for(const auto &w : words)
            freq[w]++;
        
		//comparator to sort the frequencies in the priority queue
        auto compare = [](const pair<string,int>& x, const pair<string,int>& y) {
            return x.second > y.second || (x.second == y.second && x.first < y.first);    
        };
        
		//find k most frequent words using a priority queue 
        priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(compare) > pq (compare);
        for(const auto &f : freq) {
            pq.emplace(f.first, f.second);
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> result;
        while(!pq.empty()) {
            result.insert(result.begin(), pq.top().first);
            pq.pop();
        }
        return result;
    }
};
//https://leetcode.com/problems/top-k-frequent-words/