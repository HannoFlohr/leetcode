class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> frequency;
        int sum = 0;
        
        for(const int& num : nums)
            frequency[num]++;

        for(auto &f : frequency)
            if(f.second == 1)
                sum += f.first;

        return sum;
    }
};
//https://leetcode.com/problems/sum-of-unique-elements/