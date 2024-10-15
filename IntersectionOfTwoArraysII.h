class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> count;
        for(int num : nums1) {
            ++count[num];
        }
        
        vector<int> intersection;
        for(int num : nums2) {
            if(count[num] > 0) {
                --count[num];
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};
//https://leetcode.com/problems/intersection-of-two-arrays-ii/