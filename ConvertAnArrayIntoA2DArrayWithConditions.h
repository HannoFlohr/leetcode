class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> frequency;
        for(const auto& num : nums)
            frequency[num]++;

        int max_frequency = 0;
        for(const auto& f : frequency)
            max_frequency = max(max_frequency, f.second);

        vector<vector<int>> result = vector<vector<int>> (max_frequency);
        for(const auto& f : frequency) 
            for(int i = 0; i < f.second; ++i)
                result[i].push_back(f.first);
        
        return result;
    }
};
//https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/