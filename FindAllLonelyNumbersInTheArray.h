class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> frequency;
        for(const auto &num : nums)
            frequency[num]++;

        vector<int> result;
        for(const auto &f : frequency) 
            if(f.second == 1 && frequency.find(f.first-1) == frequency.end() && frequency.find(f.first+1) == frequency.end())
                result.push_back(f.first);

        return result;
    }
};
//https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/