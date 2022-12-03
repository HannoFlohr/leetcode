class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> freq;
        for(auto &n : nums)
            if(n % 2 == 0)
                freq[n]++;
        
        int most_frequent = -1, most_frequent_number = -1;
        for(auto &f : freq)
            if(f.second > most_frequent) {
                most_frequent = f.second;
                most_frequent_number = f.first;
            }
        
        return most_frequent_number;
    }
};
//https://leetcode.com/problems/most-frequent-even-element/