class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<set<int>> contains (101);

        for(const auto& n : nums1) 
            contains[n].insert(1);
        for(const auto& n : nums2) 
            contains[n].insert(2);
        for(const auto& n : nums3) 
            contains[n].insert(3);
    
        vector<int> result;
        for(size_t i=0; i<101; i++) 
            if( contains[i].size() >= 2 )
                result.push_back(i);
    
        return result;
    }
};
//https://leetcode.com/problems/two-out-of-three/