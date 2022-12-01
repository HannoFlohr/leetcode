class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1, m2;
        for(int &n : nums1) m1[n]++;
        for(int &n : nums2) m2[n]++;
        
        vector<int> intersection;
        for(auto &i : m1) 
            if(m2[i.first] > 0) 
                intersection.push_back(i.first);
        
        return intersection;
    }
};
//https://leetcode.com/problems/intersection-of-two-arrays/