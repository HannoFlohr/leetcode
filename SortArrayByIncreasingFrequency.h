class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const auto &n : nums)
            freq[n]++;
 
        //sort nums by frequency (for equal values: keys in decreasing order)
        sort(nums.begin(), nums.end(), [&](const int &x, const int &y){
            return freq[x] == freq[y] ? x > y : freq[x] < freq[y];
        } );
        
        return nums;
    }
};
//https://leetcode.com/problems/sort-array-by-increasing-frequency/