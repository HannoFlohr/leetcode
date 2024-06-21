class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int common1 = 0, common2 = 0;
        unordered_map<int,int> frequency1;
        unordered_map<int,int> frequency2;
        for(int n : nums1) {
            frequency1[n]++; 
        }
        for(int n : nums2) {
            frequency2[n]++; 
        }

        for(auto [n,freq] : frequency1) {
            if(frequency2.contains(n)) {
                common1 += freq;
            }
        }
        for(auto [n,freq] : frequency2) {
            if(frequency1.contains(n)) {
                common2 += freq;
            }
        }

        return {common1,common2};
    }
};
//https://leetcode.com/problems/find-common-elements-between-two-arrays/