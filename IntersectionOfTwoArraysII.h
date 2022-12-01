class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        for(int &n : nums1) freq[n]++;
        
        vector<int> intersection;
        for(int &n : nums2) 
            if(freq[n] > 0) {
                freq[n]--;
                intersection.push_back(n);
            }
        
        return intersection;
    }
};
//https://leetcode.com/problems/intersection-of-two-arrays-ii/