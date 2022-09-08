class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int halfSize = arr.size() / 2;
        
        unordered_map<int,int> freq;
        for(auto a : arr) 
            freq[a]++;
        
        vector<int> values;
        for(auto f : freq)
            values.push_back(f.second);
        sort(values.rbegin(), values.rend()); 
        
        int x = 0, set = 0;
        while(x < halfSize && set<values.size()) {
            x += values[set];
            set++;
        }
        
        return set;
    }
};
//https://leetcode.com/problems/reduce-array-size-to-the-half/