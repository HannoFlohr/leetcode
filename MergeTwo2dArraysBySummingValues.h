class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> sumAtId;
        for(const auto& num : nums1) 
            sumAtId[num[0]] += num[1];
        for(const auto& num : nums2) 
            sumAtId[num[0]] += num[1];

        vector<vector<int>> result;
        for(const auto& [id,sum] : sumAtId)
            result.push_back({id,sum}); 

        return result;
    }
};
//https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/