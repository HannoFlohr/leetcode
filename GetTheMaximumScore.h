class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9+7, n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        long path1 = 0, path2 = 0;
        
        while(i1 < n1 || i2 < n2) {
            if(i1 < n1 && (i2 == n2 || nums1[i1] < nums2[i2]))
                path1 += nums1[i1++];
            else if(i2 < n2 && (i1 == n1 || nums1[i1] > nums2[i2]))
                path2 += nums2[i2++];
            else { // if cur nums1 and nums2 equal
                path1 = path2 = max(path1, path2) + nums1[i1];
                i1++, i2++;
            }
        }
        
        return max(path1, path2) % MOD;
    }
};
//https://leetcode.com/problems/get-the-maximum-score/