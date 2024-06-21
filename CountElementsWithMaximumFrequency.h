class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> frequency;
        for(int n : nums) {
            frequency[n]++;
        }

        int count = 0, max_frequency = 0;
        for(auto [_,freq] : frequency) {
            if(freq > max_frequency) {
                count = freq;
                max_frequency = freq;
            }
            else if(freq == max_frequency) {
                count += freq;
            }
        }

        return count;
    }
};
//https://leetcode.com/problems/count-elements-with-maximum-frequency/