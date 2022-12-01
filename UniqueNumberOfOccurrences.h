class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int &a : arr)
            m[a]++;
        
        unordered_set<int> f;
        for(auto &i : m) 
            if(!f.insert(i.second).second)
                return false;
        
        return true;
    }
};
//https://leetcode.com/problems/unique-number-of-occurrences/