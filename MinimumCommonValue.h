class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;

        while(index1 < nums1.size() && index2 < nums2.size()) {
            if(nums1[index1] == nums2[index2]) 
                return nums1[index1];
            else if(nums1[index1] < nums2[index2])
                index1++;
            else
                index2++;
        }

        return -1;
    }
};
//https://leetcode.com/problems/minimum-common-value/