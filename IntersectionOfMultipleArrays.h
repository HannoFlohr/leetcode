class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> freq (1001, 0);
        for(auto &num : nums) 
            for(auto &i : num) 
                freq[i]++;
            
        vector<int> intersection;
        for(int i=0; i<freq.size(); i++)
            if(freq[i] == nums.size())
                intersection.push_back(i);
        
        return intersection;
    }
};
//https://leetcode.com/problems/intersection-of-multiple-arrays/