class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const auto &n : nums)
            freq[n]++;
        
        int pairs=0, remain=0;
        for(const auto &f : freq) {
            pairs += f.second / 2;
            remain += f.second % 2;
        }
        
        return {pairs, remain};
    }
};
//https://leetcode.com/problems/maximum-number-of-pairs-in-array/

/*
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const auto &n : nums)
            freq[n]++;
        
        int pairs=0;
        for(auto &f : freq) {
            if(f.second < 2) continue;
            
            pairs += f.second / 2;
            f.second %= 2;
        }
        
        int remain=0;
        for(const auto &f : freq)
            if(f.second > 0)
                remain += f.second;
        
        return {pairs, remain};
    }
};
*/