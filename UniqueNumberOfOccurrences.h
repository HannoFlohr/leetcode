class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        for(int a : arr)
            count[a]++;
        
        unordered_set<int> frequnecies;
        for(auto &i : count) 
            if(!frequnecies.insert(i.second).second)
                return false;
        
        return true;
    }
};
//https://leetcode.com/problems/unique-number-of-occurrences/